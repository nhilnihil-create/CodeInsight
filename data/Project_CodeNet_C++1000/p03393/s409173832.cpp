#include <bits/stdc++.h>
using namespace std;
#define repd(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
#define all(x) (x).begin(),(x).end()
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
typedef long long ll;
const long long INF = 1LL << 60;
typedef pair<int, int> P;
int main()
{
    string S, ans = "";
    cin >> S;


    vector<int> alpha(26, 0);
    rep(i, S.size()) {
        alpha[S[i] - 'a']++;
    }

    int cnt = 0;
    string m = "";
    bool flag = false;
    
    rep(i, 26) {
        cnt += alpha[i];
        if (alpha[i] == 0) m += (char)(i + 'a');
    }
    if (cnt != 26) {
        ans += S + m[0];
        flag = true;
    }
    else {
        for (int i = (int)S.size() - 1; i >= 0; i--) {
            int index = (int)(S[i] - 'a');
            if (flag) ans += S[i];
            else {
                repd(i, index + 1, 26) {
                    if (alpha[i] == 0) {
                        ans += (char)('a' + i);
                        flag = true;
                        break;
                    }
                }
            }
            alpha[index] = 0;
        }
        reverse(all(ans));
    }

    cout << (flag ? ans : "-1") << endl;
    return 0;
}