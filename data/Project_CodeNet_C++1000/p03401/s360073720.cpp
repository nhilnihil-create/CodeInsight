#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    vector<int> B(N+1);
    vector<int> C(N);
    for(int n=0; n<N; n++) {
        cin >> A[n];
        if(n==0) {
            B[n]=abs(A[n]);
        } else if(n==N-1) {
            B[N]=abs(A[n]);
            B[n] = abs(A[n]-A[n-1]);
            B[n] += B[n-1];
            B[N] += B[N-1];
            
            C[N-1] = abs(A[n-1]);
        } else {
            B[n] = abs(A[n]-A[n-1]);
            B[n] += B[n-1];
        }
        
        if(n==1) {
            C[n-1] = abs(A[n]);
        } else if(n>1) {
            C[n-1] = abs(A[n]-A[n-2]);
        }
    }
    B.insert(B.begin(), 0);
    // for(int i=0; i<N+2; i++) {
    //     cout << B[i] << endl;
    // }

    for(int n=1; n<=N; n++) {
        cout << B[n-1]-B[0]+B[N+1]-B[n+1]+C[n-1] << endl;
    }
    

    return 0;
    
}