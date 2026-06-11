///supercalifragilisticexpialidocious.
#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define PB pop_back
#define pb push_back
#define mp make_pair
#define int long long
#define sz(s) (int)s.size()
#define seper(n) setprecision(n)
#define all(sum) sum.begin(),sum.end()
#define mem(a,b) memset(a,b,sizeof a)
#define IOS ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
typedef long long ll;
typedef map<int , int> mii;
typedef pair<int , int> pii;
typedef map<string , int> msi;
typedef pair<int , string> pis;
const int MAXN = 2e5 + 10;
int n , q;
string s;
pair<char , char> c[MAXN];
int f(int i)
{
    int ptr = i;
    for(int j = 0 ; j < q ; j ++)
        if(c[j].f == s[ptr])
            if(c[j].s == 'L')
                ptr --;
            else
                ptr ++;
    if(ptr < 0)
        return 0;
    if(ptr >= n)
        return 1;
    return 2;
}
int32_t main()
{
    cin >> n >> q >> s;
    for(int i = 0 ; i < q ; i ++)
        cin >> c[i].f >> c[i].s;
    int l = -1 , r = n + 1;
    while(r - l > 1)
    {
        int mid = (l + r) / 2;
        if(f(mid) == 1)
            r = mid;
        else
            l = mid;
    }
    int right = l;
    l = -1 , r = n + 1;
    while(r - l > 1)
    {
        int mid = (l + r) / 2;
        if(!f(mid))
            l = mid;
        else
            r = mid;
    }
    return cout << n - (n - 1 - right + 1) - (l + 1) + 1 << endl , 0;
}
