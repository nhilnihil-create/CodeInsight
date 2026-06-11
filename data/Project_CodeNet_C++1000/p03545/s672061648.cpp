#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int, int> pii;
#define rep(i, start, n) for (int i = (int)(start); i < (int)(n); ++i)
#define all(a) a.begin(), a.end()

const int MOD = 1e9+7;
const int INF = 2147483647;

int main(){
    string S;
    cin >> S;
    rep(i, 0, 1<<3){
        int num = (S[0] - '0');
        vector<char> ans;
        ans.push_back(S[0]);
        rep(j, 0, 3){
            if ((i>>j)&1){
                num += (S[j+1] - '0');
                ans.push_back('+');
            }
            else{
                num -= (S[j+1] - '0');
                ans.push_back('-');
            }
            ans.push_back(S[j+1]);
        }
        if (num == 7){
            for (auto s: ans){
                cout << s;
            }
            cout << "=7";
            return 0;
        }
    }
    cout << -1 << endl;
}