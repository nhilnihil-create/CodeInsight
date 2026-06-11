#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
 
int main() {
  long long N,H,W,ans;
	cin>>N>>H>>W;
	ans=0;
	rep(i,N){
	  long long A,B;
		cin>>A>>B;
		if(A>=H && B>=W) ans++;
	}
	cout<<ans<<endl;
	return 0;
}