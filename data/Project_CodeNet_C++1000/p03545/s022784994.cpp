#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
#define all(x) x.begin(),x.end()
#define rep(i,j,n) for (long long i = j; i < (long long)(n); i++)
#define _GLIBCXX_DEBUG
#define MOD 1000000007
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
//name[i][j]-> vvl name(i,vl(j))
//map<int,int>mp
//余りを切り上げる =>  (a + b - 1) / b 

signed main(){
	string s; cin>>s;
	vi v(4);
	rep(i,0,4){
		int a; string t;
		t.push_back(s[i]);
		v[i]=stoi(t);
	}
	rep(i,0,1<<3){
		int ans=v[0];
		vector<char> c(3);
		rep(j,0,3){
			if(i>>j&1){
				ans+=v[j+1];
				c[j]='+';
			}
			else{
				ans-=v[j+1];
				c[j]='-';
			}
		}
		if(ans==7){
			cout<<v[0];
			rep(k,0,3){
				cout<<c[k]<<v[k+1];
			}
			cout<<"=7"<<endl;
			return 0;
		}
	}
	
	
	
	return 0;
}