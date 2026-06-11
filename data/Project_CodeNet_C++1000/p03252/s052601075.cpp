#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
typedef long long ll;
const int INT_INF = 1e9;
const ll INF = 1LL << 30;
const ll MOD = 1e9 + 7;


int main() {
    string s, t; cin >> s >> t;

    int n = s.size();

    map<char, int> m1, m2;
    for(int i = 0; i < n; i++){
        m1[s[i]]++;
        m2[t[i]]++;
    }

    if(m1.size() != m2.size()){
        cout << "No" << endl;
        return 0;
    }

    V<int> v1, v2;
    for(auto p : m1) v1.push_back(p.second);
    for(auto p : m2) v2.push_back(p.second);

    sort(ALL(v1));
    sort(ALL(v2));

    for(int i = 0; i < (int)v1.size(); i++){
        if(v1[i] == v2[i]) continue;
        else{
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;

}
