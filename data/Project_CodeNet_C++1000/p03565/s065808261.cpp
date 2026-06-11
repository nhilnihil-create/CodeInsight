#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

const ll INF = 1LL << 60;

string S, T;
int main() {
    cin >> S >> T;
    // if (S.size() < T.size()) {
    //     cout << "UNRESTORABLE" << endl;
    //     return 0;
    // }

    // ? を aで埋める
    // set<string> candi;
    vector<string> v;

    // S の先頭決め打ち
    for (int i = 0; i < S.size(); i++) {
        // T 探索
        bool judge = true;
        for (int j = 0; j < T.size(); j++) {
           if (i + j >= S.size()) {
               judge = false;
               continue;
           }
           if (S[i + j] != T[j] && S[i + j] != '?') {
               judge = false;
               break;
           }
        }
        // cout << judge << endl;
        if (judge) {
            // 先頭
            string tmp = S.substr(0, i); 
            // replace(tmp.begin(), tmp.end(), '?', 'a');

            // 残った ? を aに置き換え
            tmp += T;

            // 後半をくっつける
            string tmp2 = S.substr(tmp.size());
            // replace(tmp2.begin(), tmp2.end(), '?', 'a');
            tmp += tmp2;
            rep(k, tmp.size()) {
                if (tmp[k] == '?') {
                    tmp[k] = 'a';
                }
            }

            // candi.insert(tmp);
            v.push_back(tmp);
        }
    }

    if (v.size() == 0) {
        cout << "UNRESTORABLE" << endl;
    } else {
        sort(v.begin(), v.end());
        // cout << *candi.begin() << endl;
        cout << v[0] << endl;
    }
}