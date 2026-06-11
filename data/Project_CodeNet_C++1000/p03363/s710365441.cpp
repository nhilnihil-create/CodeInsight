#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <map>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)

int main() {
	long long n,ans=0,str=0,sum=0;
	cin>>n;
	vector<long long>a(n),cnt(n);

	rep(i,n){
	    cin>>a[i];
	    sum+=a[i];
	    cnt[i]=sum;
	}
	cnt.push_back(0);
	sort(cnt.begin(),cnt.end());
	for(int i=0;i<n;i++){
	    if(cnt[i]==cnt[i+1]){
	        str++;
	        ans+=str;
	    }
	    else str=0;
	}
	
	cout<<ans;
	return 0;
}