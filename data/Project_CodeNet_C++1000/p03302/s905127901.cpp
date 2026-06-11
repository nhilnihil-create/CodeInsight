#include <bits/stdc++.h>
#define lol long long
using namespace std;

//const lol mod=1e9+7;

/*  author: H3XoRuSH  */

int main() {
    ios_base::sync_with_stdio(false);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol a,b;
    cin >> a >> b;
    if((a+b)==15) cout << "+";
    else if((a*b)==15) cout << "*";
    else cout << "x";
    return 0;
}
