#include<bits/stdc++.h>
#define int long long
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define sz(a) a.size()
#define re return 
#define MP make_pair
#define pb push_back
#define pii pair<int,int>
#define se second
#define fi first
using namespace std;
int read(string a){
	re (a[0]-'0')*10+(a[1]-'0');
}
bool isyear(int a){
	if(!a||a>12) re 1;
	re 0;
}
bool ismonth(int a){
	if(0<a&&a<=12) re 1;
	re 0;
}
signed main(){
	ios_base::sync_with_stdio(0);
	string s;
	cin>>s;
	int a=read(s.substr(0,2)),b=read(s.substr(2));
	if(isyear(a)&&ismonth(b)&&!isyear(b)&&!ismonth(a)){
		cout<<"YYMM";
		re 0;
	}
	if(isyear(b)&&ismonth(a)&&!isyear(a)&&!ismonth(b)){
		cout<<"MMYY";
		re 0;
	}
	if(isyear(a)&&isyear(b)){
		cout<<"NA";
		re 0;
	}
	cout<<"AMBIGUOUS";
	re 0;
}