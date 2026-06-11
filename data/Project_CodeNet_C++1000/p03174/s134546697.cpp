#include <iostream>
#include <vector>

typedef long long ll;
const int MOD = 1000000007;

int main(){
    int N;
    std::cin >> N;
    std::vector<std::vector<int> > aff(N, std::vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cin >> aff.at(i).at(j);
        }
    }
    std::vector<ll> dpt(1<<N, 0);
    dpt.at(0) = 1;

    for (int status = 1; status <= (1<<N) - 1; status++) {
        int m = __builtin_popcount(status);
        for (int f = 0; f < N; f++) {
            if (((1<<f) & status) && (aff.at(m-1).at(f))) {
                dpt.at(status) = (dpt.at(status) + dpt.at(status^(1<<f))) % MOD;
            }
        }
    }

    std::cout << dpt.at((1<<N)-1);
}
