#include<bits/stdc++.h>
#define mp make_pair
#define rep(i,n) for(int i=0;i<n;i++)
#define BINF 0x7fffffff
#define INF 0x3f3f3f3f
#define LINF 9223372036854775807
#define END(s) {cout<<s;return 0;}
#define CON(s) {cout<<s;continue;}
#define BRE(s) {cout<<s;break;}
#define pb push_back
#define all(a) a.begin(),a.end()
#define sz(a) (int)a.size()
#define F first
#define S second
#define LOCAL_JUDGE 1 //remember to change
using namespace std;
int main(){
	int t;
	cin>>t;
	rep(HateAtcoder,t){
		long long x,y;
		cin>>x>>y;
		long long pro=x*y;
		long long sq=floor(sqrt(pro));
		long long cnt=sq*2-1;
		if(sq*sq==pro && !(sq==x && sq==y)) cnt--;
		if(sq==x && sq==y) cnt--;
		else if(sq>=x) cnt--;
		else if(sq>=y) cnt--;
		if(sq*(sq+1)<pro) cnt++;
		cout<<cnt<<endl;
	}
	return 0;
}