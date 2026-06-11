#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<string,string> p;

int main(){
  int N,i,j,bi;
  cin>>N;
  map<p,ll> cnt;
  string s;
  cin>>s;
  ll ans=0;
  for(bi=0;bi<(1<<N);bi++){
	string a="", b="";
	for(i=0;i<N;i++){
		if((bi>>i)&1) a+=s[i];
		else b+=s[i];
	}
	cnt[p(a,b)]++;
  }
  for(bi=0;bi<(1<<N);bi++){
	string a="", b="";
	for(i=0;i<N;i++){
		if((bi>>i)&1) a+=s[i+N];
		else b+=s[i+N];
	}
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	ans+=cnt[p(a,b)];
  }
  cout<<ans<<endl;
  return 0;
}