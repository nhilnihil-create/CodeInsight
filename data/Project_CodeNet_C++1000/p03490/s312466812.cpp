#include <bits/stdc++.h>
typedef long long ll;
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,a) FOR(i,0,a)
	
using namespace std;
const int MAX_N=8000;
string s;
int N;
vector<int> vx,vy;
int x,y;

bool C(const vector<int> &vec,int v){
	bitset<MAX_N*2+1> dp;
	dp[MAX_N]=true;
	for(auto i:vec){
		dp=(dp<<i)|(dp>>i);
	}
	if (v<-MAX_N){
		return false;
	}
	return dp[v+MAX_N];
}
int main(){
	cin>>s>>x>>y;
	N=s.size();
	{
		bool f=false;
		REP(i,N){
			int j;
			for(j=i;j<N && s[j]=='F';j++){
			}
			if (!f){
				if (i==0){
					x-=j-i;
				}else{
					vx.push_back(j-i);
				}
			}else{
				vy.push_back(j-i);
			}
			f=!f;			
			i=j;
		}
	}
	cout<<(C(vx,x) && C(vy,y) ? "Yes" : "No")<<endl;
	return 0;
}