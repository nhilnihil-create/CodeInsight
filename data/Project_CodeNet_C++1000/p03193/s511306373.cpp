#include <iostream>
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

using namespace std;
typedef long long int lli;
//const int MAX=1e5+5;
//const int MOD=1e9+7;

int main(){
	int N,H,W;
	cin>>N>>H>>W;
	int ans=0;
	rep(i,N){
		int a,b;
		cin>>a>>b;
		if(a>=H&&b>=W)ans++;
	}
	cout<<ans;
}