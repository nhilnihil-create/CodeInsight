#include<bits/stdc++.h>
#define MOD 1000000007
#define IO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define forf(i,a,b) for(i=a;i<b;i++)
#define forr(i,a,b) for(i=a;i>b;i--)
#define mp make_pair
#define f first
#define s second
#define pb(x) push_back(x)
typedef  long long  int ll;
typedef std::vector<ll> vi;

#define input(vec,a,b) for(ll i =a;i<b;i++) cin>>vec[i]
#define print(vec,a,b) for(ll i=a;i<b;i++) cout<<vec[i]<<" " ;cout<<endl;
#define all(a) a.begin(),a.end()
using namespace std;


void solve(){
        char s[3001],t[3001];
        cin>>s>>t;
        ll n,m,i,j;
        for(n=0;s[n]!='\0';n++);
        for(m=0;t[m]!='\0';m++);
        
        ll mx[n+1][m+1]={0};
        for(i=0;i<=n;i++)
        {
                 for(j=0;j<=m;j++)
                 mx[i][j]=0;
            
        }
        for(i=1;i<=n;i++)
        {
                 for(j=1;j<=m;j++)
                 {
                          if(s[i-1]==t[j-1])
                          {
                                   mx[i][j]=mx[i-1][j-1]+1;
                                   
                          }
                          else
                          {
                                   mx[i][j]=max(mx[i-1][j],mx[i][j-1]);
                          }
                 }
        }
        ll out=mx[n][m];
        stack<char> st;
        while(out>0)
        {
                 if(s[n-1]==t[m-1])
                 {
                    out--;
                    st.push(s[n-1]);
                    n--;
                    m--;
                 }
                 else
                 {
                          if(mx[n][m-1]>mx[n-1][m])
                          {
                                   m--;
                          }
                          else
                          {
                                   n--;
                          }
                 }
        }
        while(!st.empty())
        {
                 cout<<st.top();
                 st.pop();
        }
}

int main()
{
      IO;
      ll t=1;
      //cin>>t;


      while(t--)
      {

          solve();
      }
    return 0;
}