#include<bits/stdc++.h>
using namespace std;

const int N=2e5+10;

int n;
int a[N];
int b[N];

int main() {
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++) {
	    int x; cin>>x;
	    a[i]=a[i-1]+x; 
        b[i]=b[i-1]^x;
	}
	
	int l=1; 
	long long sum=0;
	
	for(int i=1;i<=n;i++) {
	    while(a[i]-a[l-1]!=(b[i]^b[l-1])) l++;
	    sum+=i-l+1;
	}
	
	cout<<sum<<endl;
    return 0;
}