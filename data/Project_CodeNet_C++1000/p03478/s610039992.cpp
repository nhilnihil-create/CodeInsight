#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
using ll = long long;

int sum(int n){
    int sum = 0;
    while(n!=0){
        sum +=n%10;
        n/=10;
    }
    return sum;
}

int main(){
    // 制約見て！！！デカかったらlong longにすること！
    int n,a,b;
    cin>>n>>a>>b;
    int ans= 0;
    for(int i =1;i<=n;i++){
        int s = sum(i);
        if(s>= a && s<=b)ans+=i;
    }
    cout<<ans<<endl;
}