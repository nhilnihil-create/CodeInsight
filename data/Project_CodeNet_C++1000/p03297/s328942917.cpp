#include <bits/stdc++.h>
#define ALL(A) (A).begin(),(A).end()
#define ll long long
#define rep(i,n) for(int i=0;i<(n);i++)

const ll mod = 1e9+7;
const ll INF = -1*((1LL<<63)+1);
const int inf = -1*((1<<31)+1);

using namespace std;

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout<<fixed<<setprecision(20);
    ll T,A,B,C,D;
    cin >> T;
    vector<string> ans;
    rep(i,T){
        set<ll> st;
        cin >> A >> B >> C >> D;
        if(D<B){
            ans.push_back("No");
            continue;
        }
        if(A<B){
            ans.push_back("No");
            continue;
        }
        if(B==1){
            ans.push_back("Yes");
            continue;
        }
        if(C>=B){
            ans.push_back("Yes");
            continue;
        }
        ll now = A%B;
        ll add = D%B;
        if(now>C){
            ans.push_back("No");
            continue;
        }
        if(add==0){
            ans.push_back("Yes");
            continue;
        }
        int cnt = 0;
        //mod B を考える
        bool ok = 1;
        ll dis;
        ll t;
        ll last;
        while(cnt<1000){
            cnt++;
            dis = B - now;
            t = dis/add;
            last = now + t*add;
            if(last==B)last -= add;
            if(last>C){
                ok = 0;
                ans.push_back("No");
                break;
            }
            now = (last + add) %B;
        }
        if(ok)ans.push_back("Yes");
    }
    for(auto x:ans)cout << x << endl;
}