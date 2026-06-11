#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 2000006;

int a[N];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int r;
	cin>>r;
	
	if(r >= 2800) cout<<"AGC";
	else if(r >= 1200) cout<<"ARC";
	else cout<<"ABC";
	
	return 0;
}
