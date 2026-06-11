#include<bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl
typedef long long ll;
using namespace std;
int static fast = [](){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0); return 0;
}();


int main() {
    string s; int k;
    cin >> s >> k;
    set<string> cand;
    for(int len = 1; len <= min(k, int(s.size())); len++) {
        for(int i = 0; i <= s.size()-len; i++) {
            cand.insert(s.substr(i, len));
        }
    }
    int ranks = 1;
    for(string ss: cand) {
        if (ranks == k) {
            cout << ss << endl;
            break;
        }
        ranks++;
    }
    return 0;
}


