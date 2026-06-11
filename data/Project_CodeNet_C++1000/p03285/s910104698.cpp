#include <bits/stdc++.h>
 
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	long long int n;
	cin>>n;
	if(n>17){
		cout<<"Yes";
	}
	else if(n==4||n==7||n==8||n==11||n==12||n==14||n==15||n==16){
		cout<<"Yes";
	}
	else{
		cout<<"No";
	}
	return 0;
}