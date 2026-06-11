#include "bits/stdc++.h"
using namespace std;
const int maxn = 5050;
bool good(int a, int b, int c){
    int tm = min({a, b, c});
    a -= tm;
    b -= tm;
    c -= tm;
    if(a == 0 && b == 0 && c == 0) return true;
    if(a == 1 && b == 0 && c == 0) return true;
    if(a == 1 && b == 1 && c == 0) return true;
    return false;
}
int main(){
    string s;
    cin >> s;
    int a = 0, b = 0, c = 0;
    for(auto it : s){
        a += it == 'a';
        b += it == 'b';
        c += it == 'c';
    }
    bool ok = false;
    ok |= good(a, b, c);
    ok |= good(a, c, b);
    ok |= good(b, a, c);
    ok |= good(b, c, a);
    ok |= good(c, a, b);
    ok |= good(c, b, a);
    if(ok) printf("YES\n");
    else printf("NO\n");
    return 0;
}
