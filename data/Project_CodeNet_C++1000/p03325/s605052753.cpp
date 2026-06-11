#include <bits/stdc++.h>
using namespace std;
#define fv               first
#define sv               second
#define ll               long long
#define pb               push_back
#define mp               make_pair
#define pll              pair<ll,ll>
#define pii              pair<int,int>
#define READ(x)          freopen(x,"r",stdin)
#define WRITE(x)         freopen(x,"w",stdout)
#define isWorking()      cout<<"Wroking"<<endl
#define all(x)           (x).begin(),(x).end()
#define allr(x)          (x).rbegin(),(x).rend()
#define fill(x,y)        memset(x, y, sizeof(x))
#define PRINT(ok)        cout<<(ok? "YES":"NO")<<endl
#define DoublePrint(x,a) cout<<fixed<<setprecision(x)<<a<<endl
#define Fast_Input       ios_base :: sync_with_stdio(0),cin.tie(0);

const ll mod= 1e9+7,INF=1e8,mx= 1e6+5,mn=100;
int testCase=1,cas=0;

int main() {

    Fast_Input

    while(testCase--){
        int n; cin>>n;

        priority_queue <ll> q;

        ll x;

        for(int i=0; i<n; i++){
            cin >> x;
            if(x%2==0){
                q.push(x);
            }
        }
        ll cnt = 0 , ans =0;

        while(!q.empty()){

            ll y = q.top();
            q.pop();

            y/=2;
            ans ++;
            cnt +=3;

            if(y%2==0) q.push(y);
        }
        cout << ans << endl;
    }
    return 0;
}
