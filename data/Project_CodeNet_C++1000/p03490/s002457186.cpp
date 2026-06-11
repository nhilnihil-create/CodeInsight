#include <iostream>
#include <iomanip>
#include <ios> 
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <queue>
#include <stack>
#include <set>
#include <cmath>
#include <bitset>
#include <map>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define sz(c) ((int)(c).size())

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
const int MAX=30010;

bool step[16001][2];

void ans(bool x){
	if(x)cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
}

bool ok(bool fixed, vi v, int rc){
	int l=sz(v);
	bitset<20001> step[4010];
	step[0][10000]=1;
	rep(i,l)rep(x,20001)if(step[i][x]){
		step[i+1][x+v[i]]=1;
		if(!fixed || i!=0)step[i+1][x-v[i]]=1;
	}
	if(step[l][rc+10000])return true;
	else return false;
}

int main(){
	string S;
	cin>>S;
	int x,y;
	cin>>x>>y;
	vi fx, fy;
	int nowF=0;;
	int dir=1;
	bool xfixed=false;
	if(S[0]=='F') xfixed=true;
	
	rep(i,sz(S)){
		if(S[i]=='F')nowF++;
		else{
			if(nowF!=0){
				if(dir==1)fx.push_back(nowF);
				else fy.push_back(nowF);
				nowF=0;
			}
			dir*=-1;
		}
	}
	if(nowF>0){
		if(dir==1)fx.push_back(nowF);
		else fy.push_back(nowF);
	}
	
	bool okx=ok(xfixed,fx,x);
	bool oky=ok(false,fy,y);
	bool all=okx & oky;
	ans(all);
}