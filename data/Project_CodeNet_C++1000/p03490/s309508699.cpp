#include "bits/stdc++.h"
using namespace std;
using ll=long long;
#define print(n) cout<<n<<endl
#define rep(i,a,n) for(int i=a;i<n;i++)
#define ALL(s) s.begin(),s.end()
#define P pair<ll,ll>
#define vl vector<ll>
#define vi vector<int>
#define vvl vector<vector<ll>>
#define vvi vector<vector<int>>
const int M=100111;
const int inf=1000000007;
const long long INF=1e18;
int dx[4]={-1,0,1,0},dy[4]={0,-1,0,1};
int ddx[8]={1,-1,0,0,1,-1,-1,1},ddy[8]={0,0,1,-1,1,-1,1,-1};



int main() {
	int x,y;
	string s;
	cin>>s;int sl=s.length();
	cin>>x>>y;
	vi x_s,y_s;
	int syoki=0;
	rep(i,0,sl){
		if(s[i]=='F')syoki++;
		else break;
	}
	x-=syoki;
	//最初だけx軸正の方向に行くので補正.
	bool r=false;//x軸方向に向いているならtrue;
	int xstep=0,ystep=0;
	rep(i,syoki+1,sl){
		if(r){
			if(s[i]=='F')xstep++;
			if(s[i]=='T'||i==sl-1){
				x_s.push_back(xstep);
				xstep=0;
				r=false;
			}
		}else{
			if(s[i]=='F')ystep++;
			if(s[i]=='T'||i==sl-1){
				y_s.push_back(ystep);
				ystep=0;
				r=true;
			}
		}
	}
	sort(ALL(x_s),greater<>());
	sort(ALL(y_s),greater<>());
	int distx=0,disty=0;
	rep(i,0,x_s.size()){
		if(distx>=x)distx-=x_s[i];
		else distx+=x_s[i];
	}
	rep(i,0,y_s.size()){
		if(disty>=y)disty-=y_s[i];
		else disty+=y_s[i];
	}
	if(distx==x&&disty==y)print("Yes");
	else print("No");
}