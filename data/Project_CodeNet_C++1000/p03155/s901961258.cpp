#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,N) for(int i=0;i<int(N);++i)
int main() {
	int N,H,W;
	cin>>N>>H>>W;
	int ans=(N-W+1)*(N-H+1);
	cout<<ans<<endl;
}