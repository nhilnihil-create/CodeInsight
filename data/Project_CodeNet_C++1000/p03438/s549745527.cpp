#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define sz(a) a.size()
#define re return
#define all(a) a.begin(),a.end()
#define int long long
using namespace std;
int a[10004],b[10004];
signed main()
{
	int n;
	cin>>n;
	int m1=0,p2=0;
	for (int i=0;i<n;i++){
		cin>>a[i];
	}
	for (int i=0;i<n;i++){
		cin>>b[i];
	}
	for (int i=0;i<n;i++){
		if (a[i]>=b[i]){
			m1=m1+a[i]-b[i];
		}
		else if ((b[i]-a[i])%2==0){
			p2=p2+(b[i]-a[i])/2;
		}
		else {
			m1++;
			p2=p2+(b[i]-a[i])/2+1;
		}
	}
	if (m1>p2)  cout<<"No";
	else  cout<<"Yes";
	re 0;
}