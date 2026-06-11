#include <bits/stdc++.h>
using namespace std;

int64_t mod = 1000000007;
int64_t large = 9223372036854775807;
double PI = 3.141592653589793;

vector<int> x{0, 0, 0, 0, 0, 0, 1, 1, 1, 2};
vector<int> y{1, 1, 1, 2, 2, 3, 2, 2, 3, 3};
vector<int> z{2, 3, 4, 3, 4, 4, 3, 4, 4, 4};

int main()
{
    int64_t N, M = 0, A = 0, R = 0, C = 0, H = 0;
    string tmp;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> tmp;
        if (tmp[0] == 'M')
            M++;
        if (tmp[0] == 'A')
            A++;
        if (tmp[0] == 'R')
            R++;
        if (tmp[0] == 'C')
            C++;
        if (tmp[0] == 'H')
            H++;
    }
    vector<int64_t> top{M, A, R, C, H};
    int64_t ans = 0;
    for (int i = 0; i < 10; i++)
        ans += top[x[i]] * top[y[i]] * top[z[i]];
    cout << ans;
}