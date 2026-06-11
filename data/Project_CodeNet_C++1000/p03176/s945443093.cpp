#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define repA(i,a,n) for(int i=a;i<n;i++)
#define trav(a,x)for(auto &a: x)
#define fll(a) memset(a,0,sizeof(a));
#define mp make_pair
#define pb push_back
#define all(x) x.begin(),x.end()
#define F first
#define S second
#define itr(it,x) for(auto it=x.begin();it!=x.end();it++)
typedef long long ll;
typedef long double ld;
typedef pair<int,int>pii;
typedef vector<int>vi;
typedef map<int,int>ma;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
void fopen()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);   
}
void solve()
{
  int n;
  cin>>n;
  int h[n],a[n];
  rep(i,n){cin>>h[i];}
  rep(i,n){cin>>a[i];}
  set<pair<int,ll>>s;
  s.insert({0,0});
  rep(i,n)
  {
    auto it=s.lower_bound({h[i],0});
    //cout<<s.size()<<endl;
    //cout<<it->F<<"a"<<it->S<<endl;
    it--;
    //cout<<it->F<<"b"<<it->S<<endl;
    it=s.insert({h[i],a[i]+it->S}).F;
  //  cout<<it->F<<" "<<it->S<<endl;
    while(1)
    {
      auto p=next(it);
      if(p==s.end()){break;}
      if(it->S>p->S){s.erase(p);}
      else{break;}
    }

  }
  cout<<s.rbegin()->S;
//cout<<(6&-6);
}
int main()
{
  fastio;
  //fopen();
  int t;
  //cin>>t;
  rep(i,1)
  { 
    solve();
    cout<<endl;
  }
  
}
