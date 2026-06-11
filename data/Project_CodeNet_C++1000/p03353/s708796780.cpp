#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
using ll = long long;


int main() {
    string s; cin >> s;
    int k; cin >> k;

    int n = s.size();
    map<string, int> mp;
    for(int i = 0; i < n; i++){
        for(int j = 1; j <= 5; j++){
            string t = s.substr(i, j);
            mp[t]++;
        }
    }

    int c = 0;
    for(auto p : mp){
        c++;
        if(c == k){
            cout << p.first << endl;
            return 0;
        }
    }

    return 0;
}
