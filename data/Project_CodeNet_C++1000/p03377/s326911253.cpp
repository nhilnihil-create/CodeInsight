#include <bits/stdc++.h>
using namespace std;

int main(){
    int a, b, x;
    cin >> a >> b >> x;
    bool ans = false;
    if(a <= x && a + b >= x) puts("YES");
    else puts("NO");
}