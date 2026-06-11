#include <bits/stdc++.h>
using namespace std;
#define ALL(obj) (obj).begin(),(obj).end()
#define SORTD(s) sort((s).rbegin(),(s).rend())
#define rep(i,n) for(int i=0;i<(n);i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
#define PI 3.14159265358979323846264338327950L

int main() {
	string s;
  	cin>>s;
  
  	int n=s.size();
  
  	int ans=999;
  	
  	for(int i=0;i<=n-3;i++){
    	int num=(s[i]-'0')*100+(s[i+1]-'0')*10+s[i+2]-'0';
      	ans =min(ans,abs(num-753));
    }
  
  cout<<ans<<endl;
  


}