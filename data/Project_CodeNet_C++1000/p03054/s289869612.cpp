#include <bits/stdc++.h>
#define pb push_back
#define int long long
#define mp make_pair
#define inf 1000000007
#define LINF 1000000000000000007LL
#define ll long long
using namespace std;
signed main(){
	int h,w,n;
	cin>>h>>w>>n;
	string s,t;
	int sr,sc;
	cin>>sr>>sc;
	cin>>s>>t;
	int fl = false;
	string tak = "LRUD";
	string aok = "RLDU";
	for( int k=0;k<4;k++){
		int cr = sr, cc = sc;
		for(int i=0;i<n;i++){
			if( s[i] == tak[k] ){
				if( s[i] == 'L'){
					cc--;
				}
				if( s[i] == 'R'){
					cc++;
				}
				if( s[i] == 'U'){
					cr--;
				}
				if( s[i] == 'D'){
					cr++;
				}
				if( cc <= 0 || cc > w || cr <= 0 || cr > h ){
					cout<<"NO"<<endl;
					return 0;
				}
			}
			if( t[i] == aok[k] ){
				if( t[i] == 'L' && cc >= 2){
					cc--;
				}
				if( t[i] == 'R' && cc <= w-1){
					cc++;
				}
				if( t[i] == 'U' && cr >= 2){
					cr--;
				}
				if( t[i] == 'D' && cr <= h-1){
					cr++;
				}
			}
		}
	}
	cout<<"YES"<<endl;
	return 0;
}