#include <bits/stdc++.h>
using namespace std ;
#define An setprecision(16) 
int main(){
    int N,B;
    cin >> N >> B;
    if(N>=13)cout << B << endl;
    else if(N>=6)cout << B/2 << endl;
    else cout << 0 << endl;
}