#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file  
#include <ext/pb_ds/tree_policy.hpp>  
#include <functional> // for less  
using namespace         std;
#define                 int long long
#define                 double long double
#define                 pb push_back
#define                 mp make_pair
#define st(arr,a)       memset(arr,a,sizeof arr)
#define                 nl cout<<'\n'
#define bitcount(x)     __builtin_popcountll(x)
const int MOD = 1000000007ll;
#define forn(i,a,b)     for(int i=a;i<=b;i++)
#define rfor(i,a,b)     for(int i=a;i>=b;i--)
#define all(x)          x.begin() , x.end()
#define pi pair<int,int>
#define X first
#define Y second
#define N 1014159
#define  vi vector<int>
#define  v  vector
#define die exit(0)
#define alln(arr) arr+1 , arr+1+n
using namespace __gnu_pbds;  
typedef tree<int, null_type, less<int>, rb_tree_tag,  
            tree_order_statistics_node_update> oset; 

int n,m,k,arr[N],B[N];

void solve()
{
    cin>>n;
    m = (1LL<<n);
    forn(i,0,m-1)
    {
        cin>>arr[i];
    }
    int ans = 0;
    forn(i,1,m-1)
    {
        int a = 0 , b = 0;
        for(int k = i ; k>=0 ; k=(k-1)&i)
        {
            if(arr[k]>a)
            {
                b = a;
                a = arr[k];
            }
            else if(arr[k]>b)
            {
                b=arr[k];
            }
            if(k == 0)break;
        }
        ans = max(ans,a+b);
        cout<<ans<<"\n";
    }
}


signed main() 
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
    int t = 1;
    //cin>>t;
    forn(i,1,t)
    {
        solve();
        nl;
    }



    return 0;

}

//       clang++ c.cpp ; ./a.out < a.txt ;  