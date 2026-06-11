#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

int main(){
	int n;
	cin>>n;
	vector<ll>a(n);
	int res=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		res+=a[i];
	}
	int tmp=1e9,ans;
	for(int i=n;i>=0;i--){
		if(tmp>=abs(res-a[i]*n)){
			ans=i;
			tmp=abs(res-a[i]*n);
		}
	}
	cout<<ans<<endl;
	return 0;
}
