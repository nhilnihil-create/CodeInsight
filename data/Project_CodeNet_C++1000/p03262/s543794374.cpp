#include <bits/stdc++.h>
#include <numeric>
using namespace std;
#define ll long long
#define mod107 1000000007
#define rep(i, n) for (int i = 0; i < n; ++i)
#define Graph vector<vector<int>>
#define grepq priority_queue<double, std::vector<double>, std::greater<double>>
#define all(v) v.begin(), v.end()
#define PI acos(-1)
#define inf 1000000321

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int price[2000],value[2000];
ll dp[2000][2000];

int main(){
    ll N,x;
    cin >> N >> x;
    vector<ll> X(N);
    ll sa = 0;
    for(int i = 0;i < N;i++){
        cin >>X[i];
    }
    sort(all(X));
    sa = abs(x-X[0]);
    for(int i = 1;i < N;i++){
        sa = __gcd(sa,abs(x-X[i]));
    }
    cout << sa << endl;
}