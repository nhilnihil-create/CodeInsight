#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
using ll = long long;

int main(){
    // 制約見て！！！デカかったらlong longにすること！
    int N,K;
    cin>>N>>K;
    int number = 1;
        int number2 ;
    rep(i,N){
        number2 = number*2;
        if(number2-number < K){
            number = number2;
        }else{
            number+=K;
        }
    }
    cout<<number<<endl;
}