#include<bits/stdc++.h>
using namespace std;



int main(void){
    int K;
    cin>>K;
    int num_a,num_b;
    if(K%2==0){
        num_a=K/2;
        num_b=K/2;
    }else{
        num_a=(K+1)/2;
        num_b=num_a-1;
    }
    cout<<num_a*num_b<<endl;
    return 0;
}

