#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ll a,b,c;
	cin>>a>>b>>c;
	cout<<(((a>c&&c>b)||(a<c&&c<b))?"Yes":"No");
	return 0;
}
