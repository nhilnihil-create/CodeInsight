#include <bits/stdc++.h>
#include <string>
//#include<sstream>
using namespace std;
#define ll long long
#define ff first
#define ss second
#define clr(a) memset(a, 0, sizeof(a))
#define set(a) memset(a, -1, sizeof(a))
#define pb push_back
#define sz(a) ((ll)a.size())
#define all(a) a.begin(), a.end()
#define mp make_pair
#define rep(i, a, y) for (ll i = a; i <= y; i++)
#define rep2(i, b) for (int i = 0; i < b; i++)
#define repl(i, a, b) for (ll i = a; i <= b; i++)
#define ppi pair<int, int>
#define scl(x) scanf("%d", &x)
#define pcl(x) printf("%d", x)
#define FastRead                  \
    ios_base::sync_with_stdio(0); \
    cin.tie(0)
/*

     ██╗██╗   ██╗██╗  ██╗ █████╗ ███╗   ██╗
     ██║██║   ██║██║  ██║██╔══██╗████╗  ██║
     ██║██║   ██║███████║███████║██╔██╗ ██║
██   ██║██║   ██║██╔══██║██╔══██║██║╚██╗██║
╚█████╔╝╚██████╔╝██║  ██║██║  ██║██║ ╚████║
 ╚════╝  ╚═════╝ ╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═══╝

*/

int main()
{
    FastRead;
    string s;
    cin >> s;
    ll cnt = 0,cnt1=0;
    for (auto a:s)
    {
        if(a=='B')
        {
            cnt++;
        }
        else
        {
            cnt1+=cnt;
        }
    }
    cout<<cnt1<<endl;
    return 0;
}