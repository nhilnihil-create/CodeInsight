#include <iostream>
#include <cmath>
#include <vector>
#include <string>
using std::endl;
using std::cin;
using std::cout;
using std::vector;
using std::pair;
using std::string;

//for(int32_t i = 0; i < N; i++)

int main(void)
{
    int64_t N, P;
    cin >> N >> P;
    //cout << "P:" << P << " ,N:" << N << endl;

    int64_t max_yakusu = 1;
    for (int64_t i = 2; i <= std::sqrt(P); i++) {
        int64_t count = 0;
        while (P % i == 0) {
            //cout << "P:" << P << " ,i:" << i << endl;
            P = P / i;
            count ++;
        }
        while (count >= N) {
            max_yakusu *= i;
            count -= N;
        }
    }

    if (P != 1 && N == 1) {
        max_yakusu *= P;
    }

    cout << max_yakusu << endl;

    return 0;
}

