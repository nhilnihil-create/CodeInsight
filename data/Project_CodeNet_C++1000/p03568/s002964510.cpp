#include <bits/stdc++.h>
#include <numeric>
using namespace std;
#define ll long long
#define mod107 1000000007
#define rep(i, n) for (int i = 0; i < n; ++i)
using Graph = vector<vector<int>>;
#define grepq priority_queue<double, std::vector<double>, std::greater<double>>
#define all(v) v.begin(), v.end()
#define PI acos(-1) 

const ll INF = 10010001010;
const int inf = 2000000000;


typedef tuple<string, int, int> TUP;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main()
{
    int N;
    cin >> N;
    ll ans = 1;
    ll bad = 1;
    vector<int> A(N);
    for (int i = 0; i < N;i++)
    {
        cin >> A[i];
        ans *= 3;
        if(A[i] % 2== 0){
            bad *= 2;
        }
    }
    cout << ans- bad << endl;
}
