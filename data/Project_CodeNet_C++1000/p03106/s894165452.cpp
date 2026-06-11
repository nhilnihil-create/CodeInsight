#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)
#define VL vector<ll>
#define VS vector<string>
#define VB vector<bool>
#define VP vector<pair<ll,ll>>
#define VVL vector<vector<ll>>
#define VVP vector<vector<pair<ll,ll>>>
#define PL pair<ll,ll>
#define ALL(v) (v).begin(), (v).end()


int main()
{
    int A, B, K, C;
    cin >> A >> B >> K;
    vector<int> v;
 
    C = max(A, B);
 
    for (int i = 1; i <= C; i++)
    {
        if (A % i == 0 && B % i == 0)
        {
            v.push_back(i);
        }
    }
 
    sort(v.begin(), v.end(), greater<>());
 
    cout << v[K - 1];
}