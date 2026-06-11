#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
 
int main() {
  int N;
  cin >> N;
	vector<int> a(N);
	rep(i,N) cin>>a[i];
	sort(a.rbegin(),a.rend());
	long int ans=0;
	rep(i,N){
	  if (i%2==0)ans+=a[i];
	  else ans-=a[i];
	}
	cout << ans << "\n";
}