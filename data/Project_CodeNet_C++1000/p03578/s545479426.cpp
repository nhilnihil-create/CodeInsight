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
    REP(i,n){
        int p;
        cin >> p;
        d[p]++;
    }
    cin >> m;
    bool flag = true;
    REP(i,m){
        int p;
        cin >> p;
        d[p]--;
        if(d[p]<0){
            flag = false;
            break;
        }
    }
    
    if(flag) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
} 