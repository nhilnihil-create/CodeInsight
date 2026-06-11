#include <bits/stdc++.h>
 
using namespace std;
#define repr(i,a,b) for (int i=a; i<b; i++)
#define rep(i,n) for (int i=0; i< (int) n; i++)
 
 
int main() {
    int A, B, T;
    cin >> A >> B >> T ;

    int ans=0;
    for (int i = A; i < T+1 ; i +=A){
        ans += B;

    }
    
    cout << ans << endl;
    }


    
