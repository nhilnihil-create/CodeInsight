
#include <iostream>
#include <string>
#include <utility>
#include <stack>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <climits>
#include <set>
#include <cmath>
#include <numeric>
#include <iomanip>

using namespace std;

long long gcd(long long m, long long n){
    if(m < n){
        return gcd(n, m);
    }
    if(n == 0){
        return m;
    }
    return gcd(n, m % n);
}

int main(){
    int T;
    cin >> T;
    for(int i = 0; i < T; i++){
        long long A;
        long long B;
        long long C;
        long long D;
        cin >> A >> B >> C >> D;
        
        if(B > D || A < B){
            cout << "No" << endl;
        } else if(B <= C){
            cout << "Yes" << endl;
        } else {
            long long A_mod = A % B;
            long long C_mod = C % B;
            long long D_mod = D % B;
            
            long long tmp = gcd(B, D_mod);
            if(D_mod == 0){
                if(A_mod <= C_mod){
                    cout << "Yes" << endl;
                } else {
                    cout << "No" << endl;
                }
            } else {
                if(A_mod <= C_mod && tmp >= B - C_mod
                   && A_mod % tmp <= C_mod % tmp){
                    cout << "Yes" << endl;
                } else {
                    cout << "No" << endl;
                }
            }
        }
    }
    
    return 0;
}
