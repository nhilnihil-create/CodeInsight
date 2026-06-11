#include <bits/stdc++.h>
#include <numeric>
using namespace std;
#define ll long long
#define mod 100000007
#define rep(i, n) for (int i = 0; i < n; ++i)
using Graph = vector<vector<int>>;
#define grepq  priority_queue<double, std::vector<double>, std::greater<double>>

int lcm(ll a, ll b)
{
    return a * b / __gcd(a, b);
}

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};




int main(){
    int N, M;
    cin >> N >> M;
    vector<int> LIKE(M+1);
    for (int i = 0; i < N;i++)
    {
        int K;
        cin >> K;
        int A;
        for (int j = 0; j < K; j++)
        {
            cin >> A;
            LIKE[A]++;
        }
    }
    ll ans = 0;
    for (int i = 0; i <= M; i++)
    {
        if(LIKE[i] == N){
            ans++;
        }

    }
    cout << ans << endl;
}
