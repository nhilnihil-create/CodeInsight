#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0;i<n;i++)
#define REPR(i,n) for(int i=n;i>=0;i--)
#define FOR(i,m,n) for(int i=m;i<n;i++)
#define EPS (1e-7)
#define INF 1e18

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;

int vx[]={0,1,0,-1};
int vy[]={1,0,-1,0};

int dx[]={1,0,-1,1,-1,1,0,-1};
int dy[]={1,1,1,0,0,-1,-1,-1};

const ll mod=1e9+7;
const int MAX_N=300;

int main(){
	string s;
	cin>>s;
	int count[3];
	string ans;
	REP(i,3)count[i]=0;
	int type=0;
	REP(i,s.size()){
		if(s[i]=='a')count[0]++;
		else if(s[i]=='b')count[1]++;
		else if(s[i]=='c')count[2]++;
	}
	for(int i=0;i<3;i++){
		if(count[i]>0)type++;
	}
	if(type==1){
		if(count[0]>1 || count[1]>1 || count[2]>1){
			ans="NO";
		}else ans="YES";
	}else if(type==2){
		int num=0;
		if((count[0]==count[1] || count[1]==count[2] || count[2]==count[0]) && s.size()==2)ans="YES";
		else ans="NO";
	}else if(type==3){
		if(abs(count[0]-count[1])>1 || abs(count[1]-count[2])>1 || abs(count[2]-count[0])>1)ans="NO";
		else ans="YES";
	}
	cout<<ans<<endl;
	return 0;
}