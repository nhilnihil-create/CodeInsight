#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define int long long
#define inf 1000000007
#define LINF 100000000000000007LL
#define ll long long
using namespace std;
signed main(){
	int n;
	cin>>n;
	cout<<0<<endl;
	string st;
	cin>>st;
	if( st == "Vacant" )return 0;
	int ok = 0, ng = n;
	while( ng - ok > 1 ){
		int mid = (ok+ng) / 2;
		cout<<mid<<endl;
		string resp;
		cin>>resp;
		if( resp == "Vacant" ) return 0;
		if(  ( resp == st && mid%2 == 0 ) || ( resp != st && mid % 2 == 1 ) ){
			ok = mid;
		}
		else{
			ng = mid;
		}
	}
	cout<<ng<<endl;
	return 0;
}