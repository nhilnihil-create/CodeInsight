#include<bits/stdc++.h>
using namespace std;

#define int long long

int N, M;
int K[10];
int S[10][10];
int P[10];

signed main()
{
    cin >> N >> M;
    for(int i = 0; i < M; i++)
    {
        cin >> K[i];
        for(int j = 0; j < K[i]; j++)cin >> S[i][j];
    }
    for(int i = 0; i < M; i++)cin >> P[i];

    int ans = 0;
    for(int i = 0; i < (1 << N); i++)
    {
        int cnt = 0;
        for(int j = 0; j < M; j++)
        {
            int tmp = 0;
            for(int k = 0; k < K[j]; k++)
            {
                if(i & (1 << (S[j][k] - 1)))tmp++;
            }
            if((tmp % 2) == P[j])cnt++;
        }
        if(cnt == M)ans++;
    }
    cout << ans << endl;
    return 0;
}
