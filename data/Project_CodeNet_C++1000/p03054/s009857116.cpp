#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
typedef long long ll;
#define FOR(i,a,b) for(ll i=(a);i<(b);i++)
#define REP(i,a) FOR(i,0,a)
using namespace std;
ll H,W,N,sr,sc;
string S,T;
struct Vector{
	ll x,y;
	Vector(ll x=0,ll y=0):x(x),y(y){}
};
Vector operator+(Vector a,Vector b){
	return Vector(a.x+b.x,a.y+b.y);
}
void operator+=(Vector &a,Vector b){
	a=a+b;
}
bool isout(Vector v){
	return v.x<0||v.x>=W||v.y<0||v.y>=H;
}
ll yoi(ll dir,char c,Vector v){
	switch(dir){
		case 0:{
			if(c=='R'){
				return 1;
			}else if(c=='L' && v.x>0){
				return -1;
			}
			break;
		}
		case 1:{
			if(c=='D'){
				return 1;
			}else if(c=='U' && v.y>0){
				return -1;
			}
			break;
		}
		case 2:{
			if(c=='L'){
				return 1;
			}else if(c=='R' && v.x<W-1){
				return -1;
			}
			break;
		}
		case 3:{
			if(c=='U'){
				return 1;
			}else if(c=='D' && v.y<H-1){
				return -1;
			}
			break;
		}
	}
	return 0;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	map<char,Vector> mp;
	mp['L']=Vector(-1,0);
	mp['R']=Vector(1,0);
	mp['U']=Vector(0,-1);
	mp['D']=Vector(0,1);
	cin>>H>>W>>N>>sr>>sc>>S>>T;
	bool ans=false;
	REP(i,4){
		Vector v(sc-1,sr-1);
		REP(j,N){
			if(yoi(i,S[j],v)==1){
				v+=mp[S[j]];
			}
			if(isout(v)){
				ans=true;
			}
			if(yoi(i,T[j],v)==-1){
				v+=mp[T[j]];
			}
		}
	}
	cout<<(ans?"NO":"YES")<<endl;
}