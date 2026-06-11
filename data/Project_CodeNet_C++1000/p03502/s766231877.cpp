#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
using ll = long long;

int main(){
    // 制約見て！！！デカかったらlong longにすること！
    // 57

    ll N,f=0;
    cin >> N;
    int n = N;
    while(n!=0){
        f += n%10;
        n /=10;
    }

    if(N%f == 0){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }

}