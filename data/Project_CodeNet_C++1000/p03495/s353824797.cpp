#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int N,K;
    cin>>N>>K;
    int A[N];
    int d[N] = {0};
    for(int i=0;i<N;i++){
        cin>>A[i];
        d[A[i]-1] += 1;
    }
    int size = 0;
    for(int i=0;i<N;i++){
        if(d[i]!=0){
            size+=1;
        }
    }
    int kakikae = 0;
    if (K-size>=0){
    }
    else{
        sort(d,d+N);
        for(int i=N-size;i<N-K;i++){
            kakikae += d[i];
        }
    }
    cout<<kakikae<<endl;
}