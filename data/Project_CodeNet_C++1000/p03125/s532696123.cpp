#include <bits/stdc++.h>
#define c(a) cout << (a) << endl
using namespace std;
int main(){
    int a, b; cin >> a >> b;
    if(b %a == 0) c(a+b);
    else c(b-a);
}