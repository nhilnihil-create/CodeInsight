#include <bits/stdc++.h>
using namespace std;

int main () {
    int A, B, K;
    cin >> A >> B >> K;
    int kaage=__gcd(A, B);
   //kaageは50になりますな

    int count =0;
    for (int i=1; i<=kaage; i++) {
        if (kaage%i==0) {
            count++;
        }
        if (count==K) {
            cout << kaage/i << endl;
            break;
        }
    }
}
        
    
        
    

    