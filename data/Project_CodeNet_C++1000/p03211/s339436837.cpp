#include <bits/stdc++.h>
 
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	long long int minn=INT_MAX;
	string s;
	cin>>s;
	for(long long int i=0;i<s.size()-2;i++){
			long long int val1=s[i]-'0',val2=s[i+1]-'0',val3=s[i+2]-'0';
			long long int num=(val1*100)+(val2*10)+val3;
			minn=min(minn,abs(num-753));
	}
	cout<<minn;
	return 0;
}