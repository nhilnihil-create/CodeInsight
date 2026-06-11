#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG //これつけるとA[N]でもいいらしい
//for文のマクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define big 1000000007

int main(){
    int64_t n,k;
    cin>>n>>k;
    int64_t ans=0;
    if(k%2==0){
        //全部偶数->全部kの倍数
        ans += (n/k)*(n/k)*(n/k);
        //全部奇数->全部(kの倍数+k/2)
        ans += ((n+(k/2))/k)*((n+(k/2))/k)*((n+(k/2))/k);
    }
    else{//kが奇数 
    //条件を満たすa,b,cは全部kの倍数の時だけ
        ans += (n/k)*(n/k)*(n/k);

    }
    cout<<ans<<endl;
}