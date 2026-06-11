#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define _GLIBCXX_DEBUG
#define all(x) x.begin(), x.end()
using namespace std;
typedef long long ll;
typedef pair<int, int> pair;
const int inf = 1000000000; //10^9
const ll inff = 1000000000000000000; //10^18

int main(){
    string s;
    ll n;
    cin >> s >> n;
    for(int i = 0; i < min((ll)s.size(), n); i++) {
        if(s[i] >= '2') {
            cout << s[i] << endl;
            return 0;
        }
    }
    cout << '1' << endl;

    return 0;
}