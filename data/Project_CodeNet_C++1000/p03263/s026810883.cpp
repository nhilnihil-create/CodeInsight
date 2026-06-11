#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define ll long long 
#define FI first 
#define SE second
#define pb push_back 
#define eb emplace_back
#define mod 1000000007
#define all(c) (c).begin(),(c).end()
#define LB  lower_bound
#define UB  upper_bound
#define max3(a,b,c) max(c,max(a,b))
#define min3(a,b,c) min(c,min(a,b))
#define mems(s, n) memset(s, n, sizeof(s))
#define NINF -1e18
#define INF 1e18
#define int ll int
#define OOK order_of_key  //no of elements less than
#define FBO find_by_order //iterator pointing kth element;indexing starts from 0
#define CK3(x,y,z) cout<<(x)<<" "<<(y)<<" "<<(z)<<endl
#define CK4(a,b,c,d) cout<<(a)<<" "<<(b)<<" "<<(c)<<" "<<(d)<<endl

typedef pair<int,int> PII;
typedef pair<pair<int,int>,int> PPII;
typedef pair<int,pair<int,int>> PIPI;
typedef map<int,int>MII;
typedef vector<int> VI;
template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

/*int power(int a, int b)
{int x=1,y=a;while(b>0){if(b%2){x =(x*y)%mod;}y =(y*y)%mod;b/=2;}return x%mod;}
*/
//int modInverse(int a, int m) {return power(a, m-2);} //gcd(a,m)=1 


signed main()
{
ios::sync_with_stdio(false); cin.tie(0);
int T=1,T1=0;//cin>>T;
while(T1++<T)
{//cout<<"Case #"<<T1<<": ";
 int h,w;
 cin>>h>>w;
 int ar[h][w];vector<pair<PII,PII>>re;int sign=1;
 for(int i=0;i<h;i++)
 for(int j=0;j<w;j++)cin>>ar[i][j];
 int rem=0;
 for(int i=0;i<h;i++)
 {   if(sign==1)
    {
     for(int j=0;j<w;j++)
     {
         if((ar[i][j]+rem)%2==0)rem=0;
         else 
         {
             rem=1;
             if(j==w-1)
             {if(i==h-1);else re.pb({{i,j},{i+1,j}});}
             else
                re.pb({{i,j},{i,j+1}}); 
         }
     }
     sign=0;
    }
    else
    {
        sign=1;
        for(int j=w-1;j>=0;j--)
        {
            if((ar[i][j]+rem)%2==0)rem=0;
         else 
         {
             rem=1;
             if(j==0)
             {if(i==h-1);else re.pb({{i,j},{i+1,j}});}
             else
                re.pb({{i,j},{i,j-1}}); 
         }
        }
    }
 }
 cout<<re.size()<<endl;
 for(auto it:re)
 {
     cout<<it.FI.FI+1<<" "<<it.FI.SE+1<<" "<<it.SE.FI+1<<" "<<it.SE.SE+1<<endl;
 }
    
}


return 0;
}



