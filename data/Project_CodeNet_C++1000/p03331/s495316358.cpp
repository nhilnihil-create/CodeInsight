#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n,mi=1000000000,sum=0,a,b;
	string sa,sb;
	cin>>n;
	for(int i=1;i<n;i++){
		a=i;b=n-i;
		sa=to_string(a);sb=to_string(b);
		for(int j=0;j<sa.length();j++){
			sum+=stoi(sa.substr(j,1));
		}
		for(int k=0;k<sb.length();k++){
			sum+=stoi(sb.substr(k,1));
		}
		mi=min(mi,sum);
		sum=0;
	}
	cout<<mi<<endl;
	return 0;
}
