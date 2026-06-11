#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include <iomanip>
using namespace std;

int main(){
	int n,k,ans=0;
	cin>>n>>k;
	vector<int> a(100000000);
	n=n-k;
	ans++;
	for(int i=0;0<n;i++){
		n=n-k+1;
		ans++;
	}
	cout<<ans<<endl;
	
	return 0;
}