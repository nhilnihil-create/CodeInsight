#include <bits/stdc++.h>
using namespace std;
#define ALL(obj) (obj).begin(),(obj).end()
#define SORTD(s) sort((s).rbegin(),(s).rend())
#define rep(i,n) for(int i=0;i<(n);i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
#define PI 3.14159265358979323846264338327950L

int n;
int dfs(ll v,bool f_3,bool f_5,bool f_7){
	if(v>n)return 0;
  	return dfs(v*10+3, true,f_5,f_7)
      	+	dfs(v*10+5,f_3,true,f_7)
      	+	dfs(v*10+7,f_3,f_5,true)
      	+	(f_3&&f_5&&f_7);
}

int main() {

  	cin>>n;
  	ll v=0;
  	cout<<dfs(v,false,false,false)<<endl;
  
	
    }

