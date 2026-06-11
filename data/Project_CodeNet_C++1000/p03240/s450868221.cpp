#include<iostream>
#include<vector>
#include<string>

using ll = long long;

int main(){
    int n;
    std::cin >> n;
    std::vector<ll> x(n), y(n), h(n);
    ll tmpX, tmpY, tmpH = -1;
    for(int i = 0; i < n; i++){
        std::cin >> x[i] >> y[i] >> h[i];
        if(h[i] != 0 && tmpH == -1){
            tmpH = h[i]; tmpX = x[i]; tmpY = y[i];
        }
    }

    for(int cx = 0; cx <= 100; cx++){
        for(int cy = 0; cy <= 100; cy++){
            ll hh = tmpH + std::abs(tmpX - cx) + std::abs(tmpY - cy);
            // 他が満たすかどうか
            bool ok = true;
            for(int i = 0; i < n; i++){
                if(h[i] == 0){
                    if(hh - std::abs(x[i] - cx) - std::abs(y[i] - cy) > 0){
                        ok = false;
                        break;
                    }
                }else if(hh - h[i] != std::abs(x[i] - cx) + std::abs(y[i] - cy)){
                    ok = false;
                    break;
                }
            }

            if(ok){
                printf("%d %d %lld\n", cx, cy, hh);
                return 0;
            }
        }
    }


    return 0;
}
