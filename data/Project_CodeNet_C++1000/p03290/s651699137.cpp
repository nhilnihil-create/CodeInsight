#include<iostream>
#include<vector>
#include<string>

// ref : https://img.atcoder.jp/abc104/editorial.pdf
using ll = long long;

int main(){
    int d, g;
    std::cin >> d >> g;
    std::vector<ll> p(d), c(d);
    for(int i = 0; i < d; i++){
        std::cin >> p[i] >> c[i];
    }

    // 完全に解くかどうか
    ll ans = 10 * 100;
    for(int bit = 0; bit < (1 << d); bit++){
        ll score = 0;
        ll numSolved = 0;
        ll bit0max = -1;
        for(int i = 0; i < d; i++){
            if(bit & (1 << i)){
                // 完全に解く
                numSolved += p[i];
                score += 100 * (i + 1) * p[i] + c[i];
            }else{
                bit0max = i;
            }
        }

        // 中途半端に解く問題なしでいけるか？
        if(score >= g){
            ans = std::min(ans, numSolved);
        }else{
            // 中途半端に解く必要あり
            if(bit0max == -1) continue;
            for(int i = 1; i < p[bit0max]; i++){
                score += 100 * (bit0max + 1);
                numSolved++;
                if(score >= g){
                    ans = std::min(ans, numSolved);
                }
            }
        }
    }

    std::cout << ans << std::endl;

    return 0;
}
