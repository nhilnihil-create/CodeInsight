#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <deque>
#include <queue>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
typedef long long ll;
typedef pair<int,int> P;
int main() {
    string t = "keyence";
    string s;
    cin >> s;
    ll n = s.size();
    rep(i, 0, n){
        rep(j, i, n){
            string tmp = s.substr(0,i)+s.substr(j);
            if (t == tmp) {
                cout << "YES" << endl;
                return 0;
            }
        }
    }
    cout << "NO" << endl;
    return 0;
}
