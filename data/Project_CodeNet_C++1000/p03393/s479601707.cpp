#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
//const int INF = 2e9;
//const ll INF = 9e18;

string alphabet = "abcdefghijklmnopqrstuvwxyz";

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string S;
    cin >> S;
    vector<int> Snum(S.size());
    for (int i=0;i<S.size();i++){
        for (int j=0;j<alphabet.size();j++){
            if (S[i] == alphabet[j]) {
                Snum[i] = j;
            }
        }
    }
    if (Snum.size() < alphabet.size()){
        vector<bool> flag(26);
        for (int i=0;i<Snum.size();i++) {
            flag[Snum[i]] = true;
        }
        int add;
        for (int i=0;i<flag.size();i++){
            if (!flag[i]) {
                add = i;
                break;
            }
        }
        S.push_back(alphabet[add]);
        cout << S << "\n";
        return 0;
    } else {
        int pos = 0;
        for (int i=Snum.size()-1;i>0;i--){
            if (Snum[i] > Snum[i-1]) {
                pos = i;
                break;
            }
        }
        if (pos == 0) {
            cout << -1 << "\n";
            return 0;
        }
        string ans;
        for (int i=0;i<pos-1;i++){
            ans.push_back(S[i]);
        }
        vector<bool> flag(26);
        for (int i=pos;i<Snum.size();i++){
            flag[Snum[i]] = true;
        }
        int add;
        for (int i=Snum[pos-1];i<26;i++){
            if (flag[i]) {
                add = i;
                break;
            }
        }
        ans.push_back(alphabet[add]);
        cout << ans << "\n";
        return 0;
    }
}