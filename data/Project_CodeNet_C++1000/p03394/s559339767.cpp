#include<bits/stdc++.h>
#define title "title"
#define ll long long
#define ull unsigned ll
#define fix(x) fixed<<setprecision(x)
#define pii pair<int,int>
#define vint vector<int>
#define pb push_back
using namespace std;
void Freopen(){
	freopen(title".in","r",stdin);
	freopen(title".out","w",stdout);
}
int read(){
	int g=0,f=1;
	char ch=getchar();
	while(ch<'0'||'9'<ch){if(ch=='-')f=-1;ch=getchar();}
	while('0'<=ch&&ch<='9'){g=g*10+ch-'0';ch=getchar();}
	return g*f;
}
int n;
signed main(){
	n=read();
	if(n==3)cout<<"2 5 63";
	else if(n&1){
		int a[8]={6,2,10,3,9,4,8,12};
		for(int i=0;i<n;i++){
			cout<<a[i%8]<<' ';
			a[i%8]+=12;
		}
	}else{
		int a[8]={2,10,3,9,4,8,6,12};
		for(int i=0;i<n;i++){
			cout<<a[i%8]<<' ';
			a[i%8]+=12;
		}
	}return signed();
}