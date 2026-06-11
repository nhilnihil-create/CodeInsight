#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#pragma GCC optimize("Ofast")
//*********************************************DO IT NOW****************************************************************
#include<bits/stdc++.h> 
#include<random>
#define int long long   
#define pp pair<int,int> 
#define ss second 
#define ff first 
#define pb push_back
#define mod 1000000007
#define pi 3.14159265359
#define mk(arr,n,type)  type *arr=new type[n];
#define sl s1.length();
#define yes cout<< "YES"<<endl
#define no  cout<< "NO"<<endl
#define all(v) (v).begin(),(v).end()
#define s(v)   sort(v,v+n)
#define  mt mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define read(a,n) for(int i=0;i<n;i++)cin>>a[i]
#define print(a,n) for(int i=0;i<n;i++)cout<<a[i]<<" "
#define for1(i,a,n)  for(int i=0;i<n;i++)
#define rep(i, c) for(int i = 0; i < (int)c; i++)
#define set(x) cout<<fixed<<setprecision(x);
using namespace std;
//**********************************************DO IT NO****************************************************************
void fastio()
{  
  #ifndef ONLINE_JUDGE
  freopen("INPUT.txt","r",stdin);
  freopen("OUTPUT.txt","w",stdout); 
  #endif
  ios_base :: sync_with_stdio(false); 
  cin.tie(NULL) ; 
  cout.tie(NULL);
}
int dp[101][1001],ans1=1e9,dp1[1000001];
int num[10];
int a[1000000];
int l(int n)
{
    int x=0;
    while(n)
    {
        x++;
        n/=10;
    }
    return x;
}
signed main()
{   
    fastio();
    int t=1;
   // cin>>t;
    while(t--)
    {  
      int n;
      cin>>n;
      int a,b,c,d;
      vector< pair <int,int> > vect(n); 
      vector< pair <int,int> > vect1(n); 
       vector<bool> z(n, false);
      for(int i=0;i<n;i++)
      {
      cin>>a>>b;
      vect[i]={b,a};
      }
      for(int i=0;i<n;i++)
      {
      cin>>c>>d;
      vect1[i]={c,d};
      }
          sort(vect.begin(), vect.end()); 
            sort(vect1.begin(), vect1.end()); 
      int ans=0;
      for(int i=0;i<n;i++)
      {   
          int x1=vect1[i].first,x2=vect1[i].second;
          for(int j=n-1;j>=0;j--)
          {  
              int x3=vect[j].second,x4=vect[j].first;
              if(z[j])
              continue;
              if(x3>=x1)
              continue;
              if(x4<x2)
              {
                  ans++;
                  z[j]=true;
                  break;
              }
          }
      }
      
            
      cout<<ans;
    }
}
// 🍪 🍪 🍪
