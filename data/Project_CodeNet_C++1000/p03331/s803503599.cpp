#include<bits/stdc++.h>
using namespace std;
int keta(int dig);
int main(){
    int N,A,B,min=5000;
    cin >> N;
    for(A=1;A<=N-1;A++){
        B=N-A;
        int sum1=0,sum2=0;
        sum1=keta(B);
        sum2=keta(A);
        if(min>sum1+sum2){
            min=sum1+sum2;
        }
    }
    cout << min;
}

int keta(int dig){
    int sum=0;
    while(dig>0){
        sum+=dig%10;
        dig/=10;
    }
    return sum;
}