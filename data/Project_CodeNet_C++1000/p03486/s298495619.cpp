#include<bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for(int i=x;i<y;i++)
#define print(A,x,n) rep(I,0,n){cout<<(I ? " ":"")<<A[I]x;}cout<<endl;
#define pprint(A,y,m,n) rep(J,0,m){print(A[J],y,n);}
const long mod=1e9+7;
const int size=1e5;
const int inf=1e9;
int main(){
	string s,t; cin>>s>>t;
	vector<char> a,b;
	for(char c:s) a.push_back(c);
	for(char c:t) b.push_back(c);
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	reverse(b.begin(), b.end());
	rep(i,0,s.size()) s[i] = a[i];
	rep(i,0,t.size()) t[i] = b[i];
	cout<<(s < t ? "Yes" : "No")<<endl;
}