#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
using ll = long long;

int main(){
    // 制約見て！！！デカかったらlong longにすること！
    int a,b,c;
    cin >> a >>b>>c;
    int ans=0; // 最初に一枚は必ず食べれる

    if(c>b){
        ans += 2*b;
        c-=b;
    }else{
        cout<<b+c<<endl;
        return 0;
    }

    if(c>a){
        ans +=a+1;
    }else{
        ans+=c;
    }

    cout<<ans<<endl;

}