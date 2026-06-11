#include <iostream>
#include <cmath>

int main(int argc, char **argv)
{
    long N, K;
    std::cin >> N >> K;

    long ans = 0;
#if 0
    for(long a = 1; a <= N; a++){
        for(long b = 1; b <= N; b++){
            if(a % b >= K) ans++;
        }
    }
#endif
    long b;
    for(b = K+1; b <= N; b++){
        long n0 = 0, n1 = 0;
        long period = N / b;
        n0 = period * (b - K);
        if(N % b > 0){
            if(K == 0){
                n1 = (N % b);
            }else{
                n1 = (N % b) - (K - 1);
            }
        }
        ans += n0 + (n1 > 0 ? n1 : 0);
    }

    std::cout << ans << std::endl;
}
