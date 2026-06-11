#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int N;
    cin >> N;
    int A[110];
    for(int i = 0; i<N; i++){
        cin >> A[i];
    }
    int min = A[0];
    int max = A[0];
    for (int i = 0; i<N; i++){
        if(A[i] > max) max = A[i];
        if(A[i] < min) min = A[i];
    }
    cout<<max-min<<endl;
}