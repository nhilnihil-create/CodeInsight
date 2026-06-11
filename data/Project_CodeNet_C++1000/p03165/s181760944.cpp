#include<bits/stdc++.h>

typedef   long long  int ll;
typedef  long double ld;
typedef std::vector<ll> vi;
typedef std::vector<std::vector<ll> > vv;

#define MOD 1000000007
#define IO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define fo(i,a,b) for(i=a;i<b;i++)
#define mp make_pair
#define pb(x) push_back(x)
#define fi first
#define se second
#define print(vec,a,b) for(ll i=a;i<b;i++) cout<<vec[i]<<" ";cout<<endl;
#define all(a) a.begin(),a.end()
#define input(vec,a,b) for(ll i = a;i<b;i++) cin>>vec[i];
#define ms(a,val) memset(a,val,sizeof(a))
using namespace std;

const int N = 1e5 + 5;


void solve(){
            ll i,j,n,m;
            
            string a,b;
            cin>>a>>b;
            n = a.size();
            m = b.size();
            ll lcs[n+1][m+1];
            ms(lcs,0);
            
            fo(i,1,n+1)
            {
				fo(j,1,m+1)
				{
					if(a[i-1]==b[j-1])
					 lcs[i][j] = 1 + lcs[i-1][j-1];
					else
					lcs[i][j] = max(lcs[i-1][j],lcs[i][j-1]);
				}
			}
			vector<char> ans;
			for(i = n,j = m;i>0&&j>0;)
			{
				if(a[i-1]==b[j-1])
				 {ans.push_back(a[i-1]),i--,j--;}
				 else
				 {
					 if(lcs[i-1][j]>lcs[i][j-1])
						i--;
						else
						j--;
				}
			}
			//cout<<ans.size()<<endl;
			
				for(i= ans.size()-1;i>=0;i--)
				 cout<<ans[i];
				 cout<<endl;
				
				
			
            
						            









}

int main()
{
    IO;
      ll t=1,i;
     // cin>>t;


      while(t--)
      {

          solve();
      }
    return 0;
}
