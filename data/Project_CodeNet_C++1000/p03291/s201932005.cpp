#include <iostream>
#include <cmath>

#define MOD 1000000007
using namespace std;

int main(){
    string S;
    cin >> S;
    int N = S.length();
    long A[N], AB[N], ABC[N];
    long q = 1;
    for(int i=0; i<N; i++){
        if(i == 0) {
            if(S[i] == 'A' || S[i] == '?') A[i] = 1;
            else A[i] = 0;
            if(S[i] == '?') q *= 3;
            AB[i] = 0;
            ABC[i] = 0;
        }
        else{
            if(S[i] == 'A'){
                A[i] = A[i-1] + q;
                AB[i] = AB[i-1];
                ABC[i] = ABC[i-1];
            }
            if(S[i] == 'B'){
                A[i] = A[i-1];
                AB[i] = AB[i-1] + A[i-1];
                ABC[i] = ABC[i-1]; 
            }
            if(S[i] == 'C'){
                A[i] = A[i-1];
                AB[i] = AB[i-1];
                ABC[i] = ABC[i-1] + AB[i-1];
            }
            if(S[i] == '?'){
                A[i] = q + 3 * A[i-1];
                AB[i] = 3 * AB[i-1] + A[i-1];
                ABC[i] = 3 * ABC[i-1] + AB[i-1];
                q *= 3;
                q %= MOD;
            }
            A[i] %= MOD;
            AB[i] %= MOD;
            ABC[i] %= MOD;
            
        }
    } /*
    for(int i=0; i<N; i++) cout << A[i] <<" "; cout << endl;
    for(int i=0; i<N; i++) cout << AB[i] <<" "; cout << endl;
    for(int i=0; i<N; i++) cout << ABC[i] <<" "; cout << endl;
*/
    cout << ABC[N-1] << endl;
    return 0;
}