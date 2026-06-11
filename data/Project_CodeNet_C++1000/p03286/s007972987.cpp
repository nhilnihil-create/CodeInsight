#include <bits/stdc++.h>
using namespace std;
using ll = long long;

string solver(int N)
{
    int p = 0;
    if(N<0)
    {
        p = 1;
        N *= -1;
    }
    int i=0;
    for(; N >= (1LL<<i); i++)
    {
        if((1<<i & N) && i%2 != p)
        {
            N += (1LL << (i+1));
        }
    }

    bool is_start = false;
    string ans = "";
    for(; i>=0; i--)
    {
        if(N & 1<<i)
        {
            ans += "1";
            is_start = true;
        }
        else if(is_start) ans += "0";
    }
    if(!is_start) ans += "0";

    return ans;
}

int calc(int n)
{
    int res = 1;
    for(int i=0; i<n; i++)
    {
        res *= -2;
    }
    return res;
}

ll test(string s)
{
    ll ans = 0;
    for(int i=s.size()-1; i>=0; i--)
    {
        if(s[i] == '1')
        {
            ans += calc(s.size() - 1 - i);
        }
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll N;
    cin >> N;
    // std::mt19937 mt{ std::random_device{}() };
    // uniform_int_distribution<ll> dist(-100, 100);
    // while(true)
    // {
    //     N = dist(mt);
    //     cout << "input : " << N << '\n';
    //     string ans = solver(N);
    //     ll num = test(ans);
    //     if(N==num) cout << "OK\n";
    //     else
    //     {
    //         cout << "ans = " << ans << '\n';
    //         cout << "num = " << num << '\n';
    //         break;
    //     }
    // }
    cout << solver(N) << endl;

    return 0;
}
