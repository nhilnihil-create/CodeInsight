#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <functional>
#include <cassert>
#include <utility>
#include <stack>
#include <queue>
using namespace std;
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define REP(i,n) for(int i=0;i<n;i++)
#define FOR(i,n1,n2) for(int i=n1;i<n2;i++)
typedef long long ll;
typedef pair<int,int> Pii;
const int INF=(1<<30)-1;
const int MAX=310;
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int lcm(int a,int b){return a/gcd(a, b)*b;}
int a,b;
int main(){
	cin>>a>>b;
	a--;
	b--;
	char s[100][100];
	REP(i,50)
		REP(j,100)
			s[i][j]='#';
	cout<<"100 100"<<endl;
	for(int i=50;i<100;i++)
		REP(j,100)
			s[i][j]='.';
	int x=0,y=0;
	REP(i,a){
		s[x][y]='.';
		if(y==98){
			x+=2;
			y=0;
		}else{
			y+=2;
		}
	}
	x=99,y=99;
	REP(i,b){
		s[x][y]='#';
		if(y==1){
			x-=2;
			y=99;
		}else{
			y-=2;
		}
	}
	REP(i,100){
		REP(j,100){
			cout<<s[i][j];
		}
		cout<<endl;
	}
	return 0;
}
