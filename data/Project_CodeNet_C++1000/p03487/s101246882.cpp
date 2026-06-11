#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <algorithm>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)

int main() {
	int n,cnt=1,ans=0;
	cin>>n;
	vector<int>a(n);
	rep(i,n)cin>>a[i];
	sort(a.begin(),a.end());
	a.push_back(1000000007);
	rep(i,n){
	    if(a[i]<a[i+1]){
	        if(cnt>=a[i])ans+=(cnt-a[i]);
	        else ans+=cnt;
	        cnt=1;
	    }
	    else cnt++;
	}
	cout<<ans;
	return 0;
}
