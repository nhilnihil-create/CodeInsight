#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL MOD = 1000000007;
#define lcm(x, y) ((x) * (y) / __gcd((x), (y)))
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define debug(x) cout << #x << " : " << x << endl
#define part cout << "----------------------------------\n";
#include <iostream>

#define fastinput                     \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

int main()
{
    fastinput;
    LL n, i, j, k, t, temp, M, tc;
    string s;
    cin >> s;
    LL a1 = (s[0] - '0') * 10 + (s[1] - '0') * 1;
    LL a2 = (s[2] - '0') * 10 + (s[3] - '0') * 1;
    LL t1=0,t2=0;
    if(a1>=1 && a1<=12)
    {
        t1=1;
    }
    if(a2>=1 && a2<=12)
    {
        t2=1;
    }

    if(t1==1 && t2==1)
    {
        cout<<"AMBIGUOUS\n";
    }
    else if(t1==1)
    {
        cout<<"MMYY\n";
    }
    else if(t2==1)
    {
        cout<<"YYMM\n";
    }
    else
    {
        cout<<"NA\n";
    }

    return 0;
}
