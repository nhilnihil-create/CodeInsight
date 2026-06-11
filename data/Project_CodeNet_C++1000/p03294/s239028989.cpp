#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,x) for(int i=0;i<x;i++)
#define put(ans)    cout << ans << endl;

int enum_divisors(int N)
{
    vector<int> res;
    for (int i = 1; i * i <= N; ++i)
    {
        if (N % i == 0)
        {
            res.push_back(i);
            // 重複しないならば i の相方である N/i も push
            if (N / i != i)
                res.push_back(N / i);
        }
    }
    return res.size();
}

int main(){
    int n;  cin >> n;
    ll a(0);
    int b[n];
    rep(i,n){
        cin >> b[i];
        a += b[i];
    }

    a--;
    int ans(0);
    rep(i,n){
        ans += b[i]-1;
    }

    cout << ans << endl;

    return 0;
}