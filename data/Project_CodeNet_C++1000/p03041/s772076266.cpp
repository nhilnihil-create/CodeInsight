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
    cin>>n>>k;
    string s;
    cin>>s;
    for(i=0;i<n;i++)
    {
        if(i==k-1)
        {
            if(s[i]>='A' && s[i]<='Z')
            {
                s[i]=s[i]-'A'+'a';
            }
        }
    }
    cout<<s<<endl;
    

    return 0;
}
