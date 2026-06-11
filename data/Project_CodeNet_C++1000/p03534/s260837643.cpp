#include "bits/stdc++.h"
#define sz(x) (int)(x).size()
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    int f[3] = {0};
    for(char c : s){
        int d = (int)(c - 'a');
        f[d]++;
    }
    sort(f, f+3);
    if( f[2] - f[0] > 1 ){
        cout << "NO\n";
    }
    else
        cout << "YES\n";

    return 0;
}










