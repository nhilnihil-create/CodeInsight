#include"bits/stdc++.h"
#define int long long
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=(a);i<(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
#define itr(i,x) for(auto i=(x).begin();i!=(x).end();++i)
#define All(x) (x).begin(),(x).end()
#define rAll(x) (x).rbegin(),(x).rend()
using namespace std;
typedef pair<int,int> P;
const int mod=1000000007;
int gcd(int x,int y){return y?gcd(y,x%y):x;}
int lcm(int x,int y){return x*y/gcd(x,y);}
void YN(bool flg){cout<<(flg?"YES":"NO")<<endl;}
void Yn(bool flg){cout<<(flg?"Yes":"No")<<endl;}
void yn(bool flg){cout<<(flg?"yes":"no")<<endl;}
signed main(){
	int n;
	cin>>n;
	vector<int> a(n);
	bool plus=false,minus=false;
	rep(i,n){ 
		cin>>a[i];
		if(a[i]>0) plus=true;
		if(a[i]<0) minus=true;
	}
	if(!plus&&!minus){ 
		cout<<0<<endl;
		return 0;
	}
	vector<int> tmp=a;
	int m=0;
	vector<P> man;
	while(plus){
		bool ok=true;
		vector<P> b;
		rep(i,n) b.push_back(P(tmp[i],i));
		sort(All(b));
		rep(i,n-1){	
			if(tmp[i]>tmp[i+1]){ 
				tmp[i+1]+=b[n-1].first;
				man.push_back(P(b[n-1].second+1,i+2));
				m++;
				ok=false;
				break;
			}
		}
		if(ok) break;
		if(m>2*n) plus=false;
	}
	if(m<=2*n&&plus){ 
		//cout<<"test"<<endl;
		cout<<m<<endl;
		rep(i,man.size()){
			cout<<man[i].first<<" "<<man[i].second<<endl;
		}
		return 0;
	}
	tmp=a;
	m=0;
	man.clear();
	while(minus){
		bool ok=true;
		vector<P> b;
		rep(i,n) b.push_back(P(tmp[i],i));
		sort(All(b));
		rep(i,1,n){	
			if(tmp[n-i]<tmp[n-i-1]){ 
				tmp[n-i-1]+=b[0].first;
				man.push_back(P(b[0].second+1,n-i));
				m++;
				ok=false;
				break;
			}
		}
		//cout<<m<<endl;
		if(ok) break;
		if(m>2*n) minus=false;
	}
	if(m<=2*n&&minus){ 
		cout<<m<<endl;
		rep(i,man.size()){
			cout<<man[i].first<<" "<<man[i].second<<endl;
		}
		return 0;
	}
	a.at(n);
}
