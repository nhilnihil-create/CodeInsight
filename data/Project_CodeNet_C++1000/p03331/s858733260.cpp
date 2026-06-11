#include <iostream>

using namespace std;

int sumdig(int N){
    int sum = 0;
    while(N>0){
        sum += N%10;
        N /= 10;
    }
    return sum;
};

int main(){
    int N,res = 1000;
    cin>>N;
    for(int i=1;i<N;i++){
        int j = N - i;
        int sum = sumdig(i) + sumdig(j);
        if(res>sum) res = sum;
    }
    cout<<res<<endl;
}