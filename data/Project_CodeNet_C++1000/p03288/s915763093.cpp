#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define each(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define all(obj) (obj).begin(),(obj).end() 
#define dump(x)  cout << #x << " = " << (x) << endl;
typedef long long lint;
using namespace std;
int main(){
	int r;
	string ans;
	cin>>r;
	if(r<1200)ans="ABC";
	else if(r<2800)ans="ARC";
	else ans="AGC";
	cout<<ans<<endl;
}
