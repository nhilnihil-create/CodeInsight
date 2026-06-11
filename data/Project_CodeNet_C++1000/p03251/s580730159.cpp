#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
typedef long long ll;

int main(){
	int n,m;
	cin>>n>>m;
	n++;
	m++;

	int x[n];
	cin>>x[0];
	int y[m];
	cin>>y[0];
	
	for(int i=1; i<n; i++) cin>>x[i];
	for(int i=1; i<m; i++) cin>>y[i];
	sort(x,x+n);
	sort(y,y+m);


	if(x[n-1]>=y[0]) cout << "War" << endl;
	else cout << "No War" << endl;

}