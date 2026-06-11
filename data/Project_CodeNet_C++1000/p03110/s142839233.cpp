#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <queue>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)

int main() {
    int n;
    cin>>n;
    double ans=0,m;
    string c;
    rep(i,n){
    	cin>>m;
    	cin>>c;
    	if(c[0]=='J')ans+=m;
    	else ans+=m*380000.0;
    }
    cout<<setprecision(10)<<ans;
	return 0;
}
