#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef long long unsigned int ull;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; i++)
#define REPD(i, n) for (int i = 0, i##_len = (n); i < i##_len; i--)
#define SIZE(x) ((int)(x).size())
#define ALL(x) (x).begin(), (x).end()
const int MOD = 1000000007;

void Main()
{
    int a, b;
    std::cin >> a >> b;
    if(a * b % 2 == 1){
        cout << "Odd" << endl;
    }
    else{
        cout << "Even" << endl;
    }
}

int main()
{
    std::ios::sync_with_stdio(false); // printf/scanf を使わない
    std::cin.tie(0);
    std::cout << std::fixed << std::setprecision(15); // 浮動小数点数を小数点表記

    Main();

    return 0;
}
