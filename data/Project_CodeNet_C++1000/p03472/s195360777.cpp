#define _USE_MATH_DEFINES
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using ll = long long;

using namespace std;


int main() {
	int n;
	ll h;
	cin>>n>>h;
	vector<ll>a(n),b(n);
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i];
	}
	sort(a.begin(),a.end());
	reverse(a.begin(),a.end());
	sort(b.begin(),b.end());
	reverse(b.begin(),b.end());
	ll a_max=a[0];
	ll ans=0;
	for(int i=0;i<n;i++){
		if(b[i]>a_max){
			ans++;
			h-=b[i];
		}else{
			break;
		}
		if(h<=0)break;
	}
	if(h>0){
		if(h%a_max==0)ans+=h/a_max;
		else ans+=h/a_max+1;
	}
	cout<<ans<<endl;
	return 0;
}