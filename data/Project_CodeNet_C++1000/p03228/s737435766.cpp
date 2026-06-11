#include <bits/stdc++.h>

using namespace std;
#define int long long
int MOD = 1000000007;

signed main(){
    int A,B,K;
    cin >> A >> B >> K;
    
    int k = K;
    for(int i=0;i<k;i++){
        if(K>0){
            if(A%2!=0) A -= 1;
            A /= 2;
            B += A;
            K--;
        }
        
        if(K>0){
            if(B%2!=0) B -= 1;
            B /= 2;
            A += B;
            K--;
        }
        
    }
    
    cout << A << " " << B << endl;
    
    return 0;
}
