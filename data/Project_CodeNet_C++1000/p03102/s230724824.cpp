#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int ans = 0, N,M,C,sum;
//入力
    cin >> N>>M>>C;
    int A[N][M],B[N]; 
    for (int j = 0; j < M; j++)
    {
        cin >> B[j];
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> A[i][j];
        }
    }

//判定
    for (int i = 0; i < N; i++)
    {
        sum = 0;
        for (int j = 0; j < M; j++)
        {
            sum += A[i][j] * B[j];
        }
        if(sum+C>0)ans++;
    }


    cout << ans << endl;
    return 0;
}