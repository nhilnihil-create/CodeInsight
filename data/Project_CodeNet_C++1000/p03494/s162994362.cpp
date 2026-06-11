#include<bits/stdc++.h>
using namespace std;

vector<long long> input(long long N){
    long long i;
    vector<long long> output(N);
    for(i=0;i<N;i++)cin>>output[i];
    return output;
}

int main(){
    long long N,i,j,result;
    vector<long long> A;
    cin>>N;
    A=input(N);

    for(i=0;i<N;i++){
        j=0;
        while(A[i]%2==0){
            A[i]/=2;
            j++;
        }
        if(i==0)result=j;
        if(j<result)result=j;
    }

    cout<<result<<endl;
}