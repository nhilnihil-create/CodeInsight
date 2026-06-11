#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
#include<climits>
#include<string>
#include<set>
#include<numeric>
#include<map>
#include<iostream>
using namespace std;
#define rep(i,n) for(int i = 0;i<((int)(n));i++)
#define reg(i,a,b) for(int i = ((int)(a));i<=((int)(b));i++)
#define irep(i,n) for(int i = ((int)(n)-1);i>=0;i--)
#define ireg(i,a,b) for(int i = ((int)(b));i>=((int)(a));i--)
typedef long long ll;
typedef pair<ll, ll> mp;



int main(void){
	ll x,y,t=0;
	bool is_x=true,first=true,x_can=false,y_can=false;
	string s;
	vector<ll> X,Y;
	set<ll> S;
	queue<ll> Q;
	cin>>s;
	scanf("%lld%lld",&x,&y);
	rep(i,s.size()){
		if(s[i]=='F')t++;
		if(s[i]=='T'){
			if(first){
				x-=t;
				is_x=false;
				first=false;
			}else if(is_x){
				X.push_back(t);
				is_x=false;
			}else{
				Y.push_back(t);
				is_x=true;
			}
			t=0;
		}
	}
	if(first){
		x-=t;
		is_x=false;
		first=false;
	}else if(is_x){
		X.push_back(t);
		is_x=false;
	}else{
		Y.push_back(t);
		is_x=true;
	}
	//x方向が可能かどうか
	int a[16010]={},b[16010]={};
	a[s.size()]++;//0番目は0にいるということにする
	rep(i,X.size()){
		reg(j,0,2*s.size()+1){
			if(a[j]!=0){
				if(j+X[i]<=2*s.size()+1)b[j+X[i]]++;
				if(j-X[i]>=0)b[j-X[i]]++;
			}
		}
		reg(j,0,2*s.size()+1){
			a[j]=b[j];
			b[j]=0;
		}
	}
	if(a[s.size()+x]!=0)x_can=true;

	//y方向が可能かどうか
	reg(j,0,2*s.size()+1){
		a[j]=0;
		b[j]=0;
	}
	a[s.size()]++;//0番目は0にいるということにする
	rep(i,Y.size()){
		reg(j,0,2*s.size()+1){
			if(a[j]!=0){
				if(j+Y[i]<=2*s.size()+1)b[j+Y[i]]++;
				if(j-Y[i]>=0)b[j-Y[i]]++;
			}
		}
		reg(j,0,2*s.size()+1){
			a[j]=b[j];
			b[j]=0;
		}
	}
	if(a[s.size()+y]!=0)y_can=true;

	if(x_can && y_can){
		printf("Yes\n");
	}else{
		printf("No\n");
	}
	return 0;
}