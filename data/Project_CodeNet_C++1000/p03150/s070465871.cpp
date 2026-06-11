#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 1e9
#define ALL(v) v.begin(), v.end()

using namespace std;
typedef long long ll;

int main(){
    string keyence = "keyence";
    string s;
    cin >> s;

    int start = 0;
    int end = 0;

    REP(start, s.size()-1){
        FOR(end, start, s.size()){
           if (s.substr(0, start) + s.substr(end, s.size()) == keyence){
               cout << "YES" << endl;
               return 0;
           } 
        }
    }
    cout << "NO" << endl;
    return 0;
}