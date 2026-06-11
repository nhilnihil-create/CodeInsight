#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int Q;
    long A[100], B[100];
    long k;
    long ans;
    cin >> Q;
    for(int i = 0; i < Q; i++){
        cin >> A[i] >> B[i];
    }
    for(int i = 0; i < Q; i++){
        long tmp = max(A[i], B[i]);
        k = (long)sqrt(A[i]*B[i]);
        if(k*(k+1) < A[i]*B[i]){
            ans = 2*k-1;
            if((2*k - tmp + 1)*(tmp+1) >= A[i]*B[i]) ans--;
        }else{
            if(A[i] == B[i]){
                ans = 2*(k-1);
            }else{
                ans = 2*(k-1);
                if(k*k == A[i]*B[i]) ans--;
                if((2*k - tmp)*(tmp+1) >= A[i]*B[i]) ans--;
            }
        }
        cout << ans << endl;
    }
}