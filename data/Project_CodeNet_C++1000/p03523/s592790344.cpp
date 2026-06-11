#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
using ll=long long;
using vec=vector<ll>;
using Graph = vector<vector<ll>>;
#define loop(i,n) for(ll i=0;i<n;i++)
#define Loop(i, m, n) for(ll i = m;i < n;i++)
#define pool(i,n) for(ll i=n-1;i>=0;i--)
#define Pool(i, m, n) for(ll i=n-1;i>=m;i--)
#define MAX 99999999999ll
#define MIN -99999999999ll
#define setbit bitset<8>
#define flagcount __builtin_popcount
#define flag(x) (1<<x)
#define flagadd(bit,x) bit|=flag(x)
#define flagpop(bit,x) bit&=~flag(x) 
#define flagon(bit,i) bit&flag(i)
#define flagoff(bit,i) !(bit & (1<<i))
#define all(v) v.begin(),v.end()
#define low2way(v,x) lower_bound(all(v),x)
#define high2way(v,x) upper_bound(all(v),x)
#define count2way(v,x) high2way(v,x)-low2way(v,x)
#define lower(v,x) low2way(v,x)-v.begin() //1番左が0、もし見つから無いならｎを出力
#define higher(v,x) high2way(v,x)-v.begin()-1 //1番左が0、もし見つからないならn-1を出力（注意）
#define putout(x) cout<<x<<endl
#define Gput(a,b) G[a].push_back(b)
ll ctoi(char c){
	if(c>='0'&&c<='9'){
		return c-'0';
	}
	return 0;
}
int main() {
  string s;
  cin>>s;
  ll ans=false;
  if(s=="AKIHABARA")ans=true;
  
  if(s=="AKIHABAR")ans=true;
  if(s=="AKIHABRA")ans=true;
  if(s=="AKIHBARA")ans=true;
  if(s=="KIHABARA")ans=true;
  
  if(s=="AKIHABR")ans=true;
  if(s=="AKIHBRA")ans=true;
  if(s=="KIHBARA")ans=true;
  
  if(s=="AKIHBAR")ans=true;
  if(s=="KIHABRA")ans=true;
  if(s=="KIHABAR")ans=true;
  
  if(s=="KIHBRA")ans=true;
  if(s=="KIHBAR")ans=true;
  if(s=="KIHABR")ans=true;
  if(s=="AKIHBR")ans=true;
  
  if(s=="KIHBR")ans=true;
  
  
  
  
  
  if(ans)putout("YES");
  else putout("NO");
}
