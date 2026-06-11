#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for (ll i = (a); i < (b); i++)
#define REP(i,n) rep(i,0,n)

bool IsPrime(ll num)
{
    if (num < 2) return false;
    else if (num == 2) return true;
    else if (num % 2 == 0) return false; 

    double sqrtNum = sqrt(num);
    for (ll i = 3; i <= sqrtNum; i += 2)
    {
        if (num % i == 0)
        {
            return false;
        }
    }

    return num%5==1;
}

void solve() 
{
    int n;cin>>n;
    rep(i,10,55555){
        if(n==0)break;
        if(IsPrime(i)){
            cout<<i<<" ";
            n--;
        }
    }cout<<endl;
}

int main()
{
    cin.tie(0);
	ios::sync_with_stdio(false);
    solve();
    return 0;
}