#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<iomanip>
#include<map>
#include<deque>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define erep(i, n) for (int i = 0; i <= (int)(n); i++)
using p = pair<int, int>;

int main() {
    string s, t; cin >> s >> t;
    vector<string> vec(0);
    rep (i, s.size()) {
        if (s[i] == '?' || s[i] == t[0]) {
            string tmp = s;
            bool flag = true;
            rep (j, t.size()) {
                if (tmp[i + j] == '?' || tmp[i + j] == t[j]) tmp[i + j] = t[j];
                else flag = false;
            }
            if (flag) {
                replace(tmp.begin(), tmp.end(), '?', 'a');
                vec.push_back(tmp);
            }
        }
    }
    if (vec.size() == 0) cout << "UNRESTORABLE" << endl; 
    else {
        sort(vec.begin(), vec.end());
        cout << vec[0] << endl;
    }
}
