#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <algorithm>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)

int main() {
	int n,t;
	cin>>n;
	n--;
	vector<int>c(n),st(n),fr(n);
	rep(i,n)cin>>c[i]>>st[i]>>fr[i];
	rep(i,n){//for each start
	    t=0;
	    for(int j=i;j<n;j++){
	        if(t<=st[j])t=st[j];
	        else t=fr[j]*((t-1)/fr[j]+1);
	        t+=c[j];
	    }
	    cout<<t<<endl;
	}
	cout<<0<<endl;
	return 0;
}
