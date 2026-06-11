#include <bits/stdc++.h>
using namespace std;
#define REP(i,a) for(int i = 0; i < (a); i++)
#define ALL(a) (a).begin(),(a).end()
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const long long LINF = 1e18;
const long long MOD = 1e9 + 7;

signed main(){
    string s;
    int w;
    cin >> s;
    cin >> w;
    string ans;
    int n = s.size();
    REP(i,n){
        if(i % w == 0) ans.push_back(s[i]);
    }
    cout << ans << endl;
    return 0;
}