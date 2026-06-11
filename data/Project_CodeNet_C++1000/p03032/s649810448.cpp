#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll, ll>pll;
const int N = 55;
ll n, k, arr[N];
ll solve2(priority_queue<ll>pq, ll rem)
{
    ll sum = 0;
    while(pq.size() && rem && pq.top() > 0)
    {
        pq.pop();
        --rem;
    }
    while(pq.size())
    {
        sum += -pq.top();
        pq.pop();
    }
    return sum;
}
ll solve(int sz)
{
    ll mx = -1e18, rem = k;
    priority_queue<ll>pq;
    for(int i = 0;i < sz;++i)
    {
        pq.push(-arr[i]);
        rem--;
        mx = max(mx, solve2(pq, rem));
    }
    for(int i = n - 1;i >= 0 && i >= sz && rem;--i)
    {
        pq.push(-arr[i]);
        rem--;
        mx = max(mx, solve2(pq, rem));
    }
    return mx;
}
int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll mx = -1e18;
    cin >> n >> k;
    for(int i = 0;i < n;++i)
        cin >> arr[i];
    for(int i = 0;i <= min(n, k);++i)
    {
        mx = max(mx, solve(i));
    }
    cout << mx;
    return 0;
}
