#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
typedef long long ll;
const int IINF = INT_MAX;
const ll INF = 1LL << 30;
const ll MOD = 1e9 + 7;


int main() {
    string s; cin >> s;
    int k; cin >> k;

    int n = s.size();
    map<string, int> m;
    for(int i = 0; i < n; i++){
        for(int j = 1; j <= 5; j++){
            string c = s.substr(i, j);
            if(c == "") continue;
            m[c]++;
        }
    }

    int i = 0;
    for(auto p : m){
        i++;
        if(i == k){
             cout << p.first << endl;
             return 0;
        }
    }

    return 0;
}
