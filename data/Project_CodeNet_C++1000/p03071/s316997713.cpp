#include <bits/stdc++.h>
#include <numeric>
using namespace std;
#define ll long long
#define mod 100000007
#define rep(i, n) for (int i = 0; i < n; ++i)
using Graph = vector<vector<int>>;

int findSumOfDigits(int n)
{
    int sum = 0;
    while (n > 0)
    {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int lcm(ll a, ll b)
{
    return a * b / __gcd(a, b);
}

vector<string> field;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main()
{
    int A,B;
    cin >> A >> B;
    int ans = 0;
    if(A == B){
        cout << A * 2 << endl;
    }
    else{
        ans += max(A, B);
        ans += max(A, B) - 1;
        cout << ans << endl;
    }
}