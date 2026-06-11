#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int A,B;
    int maxa ;  
    cin >> A >> B;
    
    maxa = max(A,B);
    if(A == B)    cout << maxa + maxa  << endl;
    else cout << maxa + maxa -1 << endl;
    
    return 0;
}
