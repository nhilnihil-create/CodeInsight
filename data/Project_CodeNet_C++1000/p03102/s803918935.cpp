#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <queue>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)

int main() {
    int n,m,c,pt,ans=0;
    cin>>n>>m>>c;
    vector<int>b(m);
    vector<vector<int>>a(n,vector<int>(m));
    rep(j,m)cin>>b[j];
    rep(i,n)rep(j,m)cin>>a[i][j];
	rep(i,n){
		pt=c;
		rep(j,m)pt+=b[j]*a[i][j];
		if(pt>0)ans++;
	}
	cout<<ans;
	return 0;
}
