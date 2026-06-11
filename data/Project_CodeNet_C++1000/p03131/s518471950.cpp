#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
#define fast_io(); std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

int main(){
    ll k,a,b;
    std::cin >> k >> a >> b;

    //A枚以下のとき1回の操作で1枚増える
    //A枚以上ある時2回の操作でB-A枚増える
    if(b-a>1 && k-a>-1) std::cout << (b-a)*((k-(a-1))/2) + (k-(a-1))%2 + a << "\n";
    else std::cout << k+1 << "\n";
    return 0;
}
