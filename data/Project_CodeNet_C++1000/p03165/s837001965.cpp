#include <bits/stdc++.h>
#define fio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;
const int N = 3007;
int vs[N][N];

int main(){
    ///preprocessing
    #ifndef ONLINE_JUDGE
    freopen("test.inp", "r", stdin);
    #endif // ONLINE_JUDGE
    fio;
    ///code below
    string s, t;
    cin >> s >> t;
    for (int i = 0; i <= s.length(); i++){
        for (int j = 0; j <= t.length(); j++){
            if (i != 0 && j != 0){
                if (s[i - 1] == t[j - 1]){
                    vs[i][j] = vs[i - 1][j - 1] + 1;
                }else{
                    vs[i][j] = max(vs[i - 1][j], vs[i][j - 1]);
                }
            }else{
                vs[i][j] = 0;
            }
        }
    }
    string o = "";
    int i = s.length();
    int j = t.length();
    while (i > 0 && j > 0){
        if (s[i - 1] == t[j - 1]){
            o = s[i - 1] + o;
            i--;
            j--;
        }else{
            if (vs[i - 1][j] > vs[i][j - 1]){
                i--;
            }else{
                j--;
            }
        }
    }
    cout << o;
}
