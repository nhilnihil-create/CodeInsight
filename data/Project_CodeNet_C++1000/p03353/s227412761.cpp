#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) for(int i=0;i<(n);++i)
#define COUT(x) cout<<(x)<<"\n"

int main(){
    string s;
    cin >> s;
    int k;
    cin >> k;
    set<string> set1;
    REP(i,s.size()){
        REP(j,k+1){
            string str = s.substr(i,j);
            set1.insert(str);
        }
    }
    auto itr = set1.begin();
    for(int i=0;i<k;i++){
        ++itr;
    }
    COUT(*itr);
    return 0;
}