#include <iostream>

using namespace std;

int main(void){
    int n, i, j, sum=0;
    cin >> n;
    
    int *A = new int[n];
    for(i=0; i<n; i++){
        cin >> A[i];
        sum += A[i];
    }
    
    bool flag = true;
    
    for(i=0; i<n; i++){
        for(j=i+1; j<n; j++){
            if(A[i] >= sum - A[i]){
                flag = false;
            }
        }
    }
    
    if(flag){
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    delete [] A;
    return 0;
}