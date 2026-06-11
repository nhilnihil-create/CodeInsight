#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
#define ld long double
#define ll long long
#define mod 1000000007
#define IINF INT_MAX
#define INF 1LL << 30


int main() {
    int n, k; cin >> n >> k;
    k--;
    string s; cin >> s;

    for(int i = 0; i < n; i++){
        if(i == k){
            char c = s[i] + 32;
            cout << c;
            // if(s[i] == 'A') cout << 'a';
            // if(s[i] == 'B') cout << 'b';
            // if(s[i] == 'C') cout << 'c';
        }else{
            cout << s[i];
        }
    }
    cout << "\n";

    return 0;
}
