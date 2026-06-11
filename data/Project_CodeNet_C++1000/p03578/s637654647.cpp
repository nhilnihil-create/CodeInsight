#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) for(int i=0;i<(n);++i)
#define REPR(i,n) for(int i=n;i>=0;i--)
#define ALL(v) (v.begin(),v.end())
#define COUT(x) cout<<(x)<<endl

int main(){
    int n,m;
    cin >> n;
    map<int,int> d;
    map<int,int> t;
    REP(i,n){
        int p;
        cin >> p;
        d[p]++;
    }
    cin >> m;
    REP(i,m){
        int p;
        cin >> p;
        t[p]++;
    }
    bool flag = true;
    
    for(const auto& i:t){
        if(t[i.first]>d[i.first]){
            flag = false;
            break;
        }
    }
    if(flag) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}    