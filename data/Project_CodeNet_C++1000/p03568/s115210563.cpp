#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
#define fast_io(); std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

int main(){
    int n, e=0;
    std::cin >> n;
    rep(i,n){
        int ai; std::cin >> ai;
        if(!(ai%2)) e++;
    }

    std::cout << pow(3,n)-pow(2,e) << "\n";
    return 0;
}