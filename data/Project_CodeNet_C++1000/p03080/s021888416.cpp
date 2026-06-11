#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < ll(n); i++)

int main() {
    int n;
    string s;
    cin >> n >> s;
    int diff = 0;
    for(char c : s){
        if (c == 'R') diff++;
        else
            diff--;
    }
    if (diff > 0) puts("Yes");
    else
        puts("No");
}