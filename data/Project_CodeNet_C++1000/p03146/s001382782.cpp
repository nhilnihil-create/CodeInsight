using namespace std;
#include<bits/stdc++.h>
#define int long long
#define pb push_back 
#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
#define repa(i,a,b) for (int i=a; i<=b; i++)
#define repd(i,b,a) for (int i=b; i>=a; i--)
#define endl "\n"
//debugging
#define debug1(a) cout<<#a<<" = "<<(a)<<endl;
#define debug2(a,b) cout<<#a<<" = "<<(a)<<", "<<#b<<" = "<<(b)<<endl;
#define debug3(a,b,c) cout<<#a<<" = "<<(a)<<", "<<#b<<" = "<<(b)<<", "<<#c<<" = "<<(c)<<endl;
#define debug4(a,b,c,d) cout<<#a<<" = "<<(a)<<", "<<#b<<" = "<<(b)<<", "<<#c<<" = "<<(c)<<", "<<#d<<" = "<<(d)<<endl;

const int N = 1e+6+5;
int big = 1e+18+3;
int mod = 1e+9+7;

signed main()
{
    IOS;
        
    int s; cin>>s;

    map<int,int>exist;
    exist[s]=1;
    int prev = s;
    for (int i=2; ;i++)
    {
        int res;
        if ( prev%2==0 )
            res = prev/2;
        else
            res = prev*3+1;
        if (exist[res])
        {
            cout<<i<<endl;
            return 0;
        }
        exist[res]=1;
        prev = res;
    }

}