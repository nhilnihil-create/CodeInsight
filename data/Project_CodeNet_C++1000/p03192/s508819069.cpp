#include <bits/stdc++.h>

#define ll long long
#define PB push_back
#define PF push_front
#define L size
#define vi vector<int>
#define MOD 1000000007
#define mp make_pair
#define fi first
#define se second


using namespace std;
ll fib(int n);
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int cnt=0;
    while(n)
    {
        if(n%10==2)cnt++;
        n/=10;
    }
    cout << cnt;
    
}
ll fib(int n)
{
    vector<ll> a;
    a.PB(0);a.PB(1);
    for(int i=2;i<=n+1;i++)
       a.PB(a[i-1]+a[i-2]);
    return a.back();
}