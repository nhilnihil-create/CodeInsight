#include <bits/stdc++.h>
#include <math.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rrep(i, n) for(int i = (n-1); i >= 0; i--)
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
const ll INF = 1LL<<62;
const int IINF = 1000000000;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using Graph = vector<vector<int>>;

typedef pair<int, int> P;

int main(){
    string S; cin >> S;
    
    vector<int> counter(26,0);
    if (S.size() < 26){
        rep(i,S.size()){
            counter[S[i]-'a']++;
        }

        char ans = 0;
        rep(i,26){
            if (counter[i] == 0){
                ans = 'a' + i;
                break;
            }
        }
        cout << S + ans << endl;
    }
    else{
        string t = S;
        sort(t.rbegin(), t.rend());

        // 辞書順で最後であった場合
        // zyx....cbaの場合
        if (S == t){
            cout << -1 << endl;
            return 0;
        }

        t = S;
        next_permutation(t.begin(), t.end());

        string ans = "";
        rep(i,S.size()){
            ans += t[i];
            if (t[i] > S[i]){
                break;
            }
        }
        cout << ans << endl;
    }
}