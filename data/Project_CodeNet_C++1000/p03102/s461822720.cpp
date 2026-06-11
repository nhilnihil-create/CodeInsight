#include<bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n,m,c,count=0;
	cin>>n>>m>>c;
	vector<int> b(m),a(m);

	for(auto& i:b)
		cin>>i;

	long long int dot_product;

	for(int i=0;i<n;i++){
		for(auto& i:a)
			cin>>i;

		dot_product=0;
		for(int i=0;i<m;i++)
			dot_product+=a[i]*b[i];

		if(dot_product + c > 0)
			count++;
	}
	cout<<count;
}