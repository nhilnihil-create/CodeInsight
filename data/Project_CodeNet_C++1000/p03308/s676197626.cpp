#include<iostream>
#include<string>
using namespace std;
int main() {
    int N;
    cin >> N;
    int A[N];
    for(int i = 0; i < N; i++)
        cin >> A[i];
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(A[i] < A[j]) {
                int t = A[i];
                A[i] = A[j];
                A[j] = t;
            }
        }
    }    
    cout << A[N-1]-A[0] << endl;
    
    return 0;
}