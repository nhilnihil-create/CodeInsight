#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)n; i++)
typedef long long ll;

int main(){
    string s;
    cin >> s;
    int w;
    cin >> w;
    string t;
    int c = 0;
    while(c < s.length()){
        t += s[c];
        c += w;
    }
    cout << t << endl;
    return 0;
} 