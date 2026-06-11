#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
#define ll long long
#define MOD 1000000007
typedef vector<int> vi;
typedef pair<int,int> pi;
#define inf 1e18
#define For(i,a,b) for (int i = a; i < b; i++)
#define Rep(i,a,b) for (int i = a; i <= b; i++)
#define ps(x,y) fixed << setprecision(y) << x 
#define pb push_back 
#define mp make_pair 
 
int32_t main()
{
    fast;
    string s; cin >> s;
    int a, b, c, d;
    a = s[0] - '0', b = s[1] - '0', c = s[2] - '0', d = s[3] - '0';
    if (a -b -c - d ==7) printf ("%d-%d-%d-%d=7\n " ,a ,b ,c , d );
    else if (a -b - c + d ==7) printf ("%d-%d-%d+%d=7\n " ,a ,b ,c , d );
    else if (a - b +c - d ==7) printf ("%d-%d+%d-%d=7\n " ,a ,b ,c , d );
    else if (a - b + c + d ==7) printf ("%d-%d+%d+%d=7\n " ,a ,b ,c , d );
    else if ( a +b -c - d ==7) printf ("%d+%d-%d-%d=7\n " ,a ,b ,c , d );
    else if ( a +b - c + d ==7) printf ("%d+%d-%d+%d=7\n " ,a ,b ,c , d );
    else if ( a + b +c - d ==7) printf ("%d+%d+%d-%d=7\n " ,a ,b ,c , d );
    else if ( a + b + c + d ==7) printf ("%d+%d+%d+%d=7\n " ,a ,b ,c , d );
    
    return 0;
}