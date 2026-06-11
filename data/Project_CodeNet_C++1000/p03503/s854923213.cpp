#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define Yes                \
    cout << "Yes" << endl; \
    return 0;
#define No                \
    cout << "No" << endl; \
    return 0;
using namespace std;
using ll = long long;
const int INF = 1001001001;
const int MOD = 1000000007;
typedef long long ll;

template <typename T>
void print(const T &v);

int main()
{
    int N;
    cin >> N;
    vector<vector<int>> F(N, vector<int>(10));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cin >> F[i][j];
        }
    }
    vector<vector<int>> P(N, vector<int>(11));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < 11; j++)
        {
            cin >> P[i][j];
        }
    }
    int maxi = -INF;
    for (int i = 1; i <= 1023; i++) // 全通り試行する
    {
        int total = 0;
        for (int j = 0; j < N; j++) // j番目の店舗について試行する
        {
            bitset<10> bs(i);
            int cnt = 0;
            for (int k = 0; k < 10; k++)
            {
                if (bs.test(k)) // k日目のbitが立っているか
                {
                    if (F[j][k] == 1)
                    {
                        cnt++;
                    }
                }
            }
            total += P[j][cnt];
        }
        maxi = max(total, maxi);
    }
    cout << maxi << endl;
}

// Use For Debug
template <typename T>
void print(T const &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (i)
            cout << " ";
        cout << v[i];
    }
    cout << endl;
}
