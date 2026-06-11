/*
ID: tanser.1
TASK: gift1
LANG: C++14
*/
#include <bits/stdc++.h>
//------
#define IC ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long
#define db double
#define str string
//------
using namespace std;
//-------------------------
const int maxn=2e5+10;
ll n , a[maxn] , i , ans , cur ;
bool yes=1 ;
//-------------------------
int main()
{IC
/*
    ofstream cout ("gift1.out");
    ifstream cin ("gift1.in");
*/
    cin >> n ;
    for(i=0 ; i<n ; i++)
        cin >> a[i];
    for(i=n-2 ; i>=0 ; i--)
    {
        if(a[i]>i || a[i]<max(0LL,a[i+1]-1))
        {
            yes=0;
            break;
        }
    }
    if(!yes || a[0])
    {
        cout << "-1\n";
        return 0;
    }
    else
    {
        for(i=n-1 ; i>=0 ; i--)
        {
            if(cur<a[i])
            {
                cur=a[i];
                ans+=a[i];
            }
            cur=max(0LL,cur-1);
        }
    }
    cout << ans << endl ;
    return 0;
}
