#include <bits/stdc++.h>
using namespace std;
#define rep(i,s,n) for(int i = s;i<n;i++)
#define repe(i,s,n) for(int i = s;i<=n;i++)
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef pair<int,int>pint;
typedef vector<int>vint;
typedef vector<pint>vpint;
static const ll maxLL = (ll)1 << 62;
const ll MOD=1000000007,INF=1e18;
int dy[]={-1,0,1,0};
int dx[]={0,1,0,-1};

#define int ll

string s;
int a=0,b=0,c=0;

signed main(){
   cin>>s;
   if(s.size()==1){
       cout<<"YES"<<endl;
       return 0;
   }
   rep(i,0,s.size()){
       if(s[i]=='a')a++;
       else if(s[i]=='b')b++;
       else c++;
   }
   b-=a;c-=a;
   if(abs(b)>=2||abs(c)>=2||abs(b-c)>=2)cout<<"NO"<<endl;
   else cout<<"YES"<<endl;
   
   
   
   return 0;
}