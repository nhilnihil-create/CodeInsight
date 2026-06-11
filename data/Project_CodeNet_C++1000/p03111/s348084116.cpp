#include<bits/stdc++.h>
#define rep(i,N) for(int i=0;i<(N);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e12;
const int inf = 1e9;
const int mod = 1e9+7;
typedef long long ll;
typedef pair<ll,int> P;
typedef set<int> S;

int n,a,b,c;
int ans = inf;
vector<int> l(8);

void solve(vector<int> v){
    if(v.size()==n){
        int now = 0;
        int cnt = 0;
        set<int> sc;
        rep(i,n){
            if(v[i]!=3 && sc.find(v[i])!=sc.end()) cnt++;
            sc.insert(v[i]);
        }
        vector<int> s(3,0);
        rep(i,n){
            if(v[i]!=3)s[v[i]] += l[i];
        }
        bool ok = 1;
        rep(i,3) if(s[i]==0) ok = 0;
        if(ok){
            now += abs(a - s[0]) ;
            now += abs(b - s[1]) ;
            now += abs(c - s[2]) ;
            now += cnt*10;
            ans = min(ans,now);
        }
    }else{
        rep(i,4){
            vector<int> copy = v;
            copy.push_back(i);
            solve(copy);
        }
    }
}

int main(){
    cout << fixed << setprecision(10);

    cin >> n >> a >> b >> c;
    rep(i,n) cin >> l[i];
    vector<int> init;
    solve(init);
    cout << ans << endl;
    return 0;
}