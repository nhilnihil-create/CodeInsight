#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 2000006;

int a[N];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int a,b,c;
	cin>>a>>b>>c;
	cout<<max({a,b,c})-min({a,b,c});
	
	return 0;
}
