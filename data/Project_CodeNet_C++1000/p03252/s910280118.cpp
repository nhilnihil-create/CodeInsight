#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
#define ld long double
#define ll long long

const int MOD =  1000000007;
const int IINF = INT_MAX;
const ll INF = 1LL << 60;


int main() {
    string s, t; cin >> s >> t;
    int n = s.size();
    map<char, int> ms, mt;
    for(int i = 0; i < n; i++){
        ms[s[i]]++;
        mt[t[i]]++;
    }

    if(ms.size() == mt.size()){
        for(int i = 0; i < n; i++){
            if(ms[s[i]] == mt[t[i]]) continue;
            else{
                cout << "No" << endl;
                return 0;
            }
        }
        cout << "Yes" << endl;
        return 0;
    }
    cout << "No" << endl;

    return 0;
}
