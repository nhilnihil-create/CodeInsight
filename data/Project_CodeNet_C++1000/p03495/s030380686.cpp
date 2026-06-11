#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include <iomanip>
using namespace std;

int main(){
	long long int n,k,c=0,ans=0;
	cin>>n>>k;
	vector<int>a(200000);
	vector<int>b(200000);
	for(int i=0;i<n;i++){
		cin>>a[i];
		b[a[i]-1]++;
	}
	sort(b.begin(),b.end(),greater<>());
	for(int i=0;b[i]!=0;i++){
		c=i;
	}
	for(int i=c;i>k-1;i--){
		ans+=b[i];
	}
	cout<<ans<<endl;

	return 0;
}