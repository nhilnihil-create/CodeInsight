#include <iostream>
#include <algorithm>
using namespace std;
int main(void){
    int N;
    int A[101];
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>A[i];
    }
    sort(A,A+N);
    printf("%d",A[N-1]-A[0]);
}