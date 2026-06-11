#include <bits/stdc++.h>
#include <math.h>

using namespace std;

long long inf=1000000007;

int main(){
	long long n,h;
	cin>>n>>h;
	vector<long long> a(n);
	vector<long long> b(n);
	for(int i=0;i<n;i++){
		cin>>a.at(i);
		cin>>b.at(i);
	}

	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());

	long long top=a.at(0);
	long long ans=0;

	for(auto t:b){
		if(t<top) break;

		h-=t;
		ans++;
		if(h<=0){
			cout<<ans<<endl;
			return 0;
		}
	}

	cout<<ans+(long long)ceil((double)h/top)<<endl;

	return 0;
}
