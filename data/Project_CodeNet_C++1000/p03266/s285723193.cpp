#include<iostream>
#include<vector>
#include<string>

using ll = long long;

int main(){
    int n, k;
    std::cin >> n >> k;

    ll sum = 0;
    for(int a = 1; a <= n; a++){
        // a + b, a + cの条件より
        int r;
        if(a % k == 0) r = 0;
        else r = k - a % k;
        // b + cはkの倍数の条件より
        if((r + r) % k != 0) continue;
        // b = r, r + k, r + 2k, ..., r + interval * k
        // c = 同上
        ll interval = (n - r) / k;
        if(r == 0){
            // このときはb = rとかはNG
            sum += interval * interval;
        }else{
            // b = rもOK
            sum += (interval + 1) * (interval + 1);
        }
    }

    std::cout << sum << std::endl;
    return 0;
}
