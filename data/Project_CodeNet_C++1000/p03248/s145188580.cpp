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
    cin >> s;
    int n = s.size();
    if(s[0] == '0' || s[n - 1] == '1'){
        cout << -1 << endl;
        return 0;
    }
    for(int i = 0; i < n / 2; i++){
        if(s[i] != s[n - 2 - i]){
            cout << -1 << endl;
            return 0;
        }
    }
    cout << 1 << " " << 2 << endl;
    int now = 2;
    for(int i = 2; i < n; i++){
        cout << now << " " << i + 1 << endl;
        if(s[i - 1] == '1') now = i + 1;
    }
    return 0;
}