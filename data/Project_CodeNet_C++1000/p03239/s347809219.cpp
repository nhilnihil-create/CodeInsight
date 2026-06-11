#include <algorithm>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string>
#include <stack>
#include <sstream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

using namespace std;
typedef long long int ll;
#define INF 1000000000

int main(){
	int n,T;
	cin>>n>>T;
	int ans = INF;
	rep(i,n){
		int c,t;
		cin>>c>>t;
		if( t <= T){
			ans = min(ans,c);
		}
	}
	if( ans == INF){
		cout<<"TLE"<<endl;		
	}else{
		cout<<ans<<endl;
	}
	return 0;
}
