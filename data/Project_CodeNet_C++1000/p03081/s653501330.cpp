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
const int MAX=2e5+5;

int main(){
	int N,Q;
	cin>>N>>Q;
	char s[MAX],t[MAX],d[MAX];
	s[0]='0',s[N+1]='0';
	rep1(i,N)cin>>s[i];
	rep1(i,Q)cin>>t[i]>>d[i];
	int x=0,y=N+1;
	for(int i=Q;i>=1;i--){
		if(s[x+1]==t[i]&&d[i]=='L')x++;
		if(s[x]==t[i]&&d[i]=='R')x--;
		if(s[y-1]==t[i]&&d[i]=='R')y--;
		if(s[y]==t[i]&&d[i]=='L')y++;
	}
	cout<<max(0, y-x-1)<<endl;
}