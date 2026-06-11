#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
using ll = long long;

int main(){
    // 制約見て！！！デカかったらlong longにすること！
    int a,b,c,k;
    cin >> a>>b>>c>>k;
    int m = std::max(a,b);
    m = std::max(m,c);

    int ans = 0;
    if (a==m){
        ans += b + c;
    }else if(b==m){
        ans+= a+c;
    }else if(c==m){
        ans += a+b;
    }
    
    for(int i =0;i<k;i++){
        m = 2*m;
    }

    ans += m;

    cout << ans <<endl;
}