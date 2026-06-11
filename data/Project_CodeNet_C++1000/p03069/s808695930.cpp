#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
const int inf = 1e9;
const ll INF = 1e18;
const double pi = 3.14159265358979323846;

int main(){//予選決勝法、左と右の予選に分けてそれらの最大で決勝をする
	int n;cin>>n;
	string s;cin>>s;

	int l[n+1],r[n+1];//境目で左右に分けて、左側にある白の数と右側にある黒の数を足して
	l[0]=0;r[n]=0;//小さいものを答えとする

	for(int i=0;i<n;i++){
		if(s[i]=='#') l[i+1]=l[i]+1;
		else l[i+1]=l[i];
	}
	for(int i=n-1;i>=0;i--){
		if(s[i]=='.') r[i]=r[i+1]+1;
		else r[i]=r[i+1];
	}

	int ans=inf;
	for(int i=0;i<=n;i++) ans=min(ans,l[i]+r[i]);

	cout<<ans<<endl;
}