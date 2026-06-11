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
//const int MAX=;
 
int main(){
	int N;
	cin>>N;
	int A[1<<18];
	rep(j,1<<N)cin>>A[j];
	
	
	int p[1<<18], q[1<<18];
	rep(j,1<<N){
		p[j]=A[j];
		q[j]=0;
	}
	
	rep(i,N)rep(j,1<<N)if((j & 1<<i)){
		int x[4];
		x[0]=p[j];x[1]=q[j];x[2]=p[j ^ (1<<i)];x[3]=q[j ^ (1<<i)];
		sort(x,x+4);
		p[j]=x[3];q[j]=x[2];
	}
	int s[1<<18];
	rep(j,1<<N){
		s[j]=p[j]+q[j];
	}
	int ans=0;
	rep1(j,(1<<N)-1){
		ans=max(ans,s[j]);
		cout<<ans<<endl;
	}
}