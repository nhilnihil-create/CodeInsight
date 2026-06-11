#include <bits/stdc++.h>

#define ll long long 
#define sz(x) (int)x.size()

using namespace std;

int main(){
	int x;
	cin>>x;
	int ans=1;
	while(ans*ans<=x)ans++;
	ans--;
	cout<<ans*ans;
}



