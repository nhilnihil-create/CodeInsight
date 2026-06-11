#include <bits/stdc++.h>
using namespace std;

int main(void){
    char A, B, ans;
    cin >> A >> B;
    if(A > B) ans = '>';
    if(A == B) ans = '=';
    if(A < B) ans = '<';
    
    cout << ans << endl;

    return 0;
}

