#include <bits/stdc++.h>
#define pb push_back
#define int long long
#define mp make_pair
#define inf 1000000007
#define LINF 1000000000000000007LL
#define ll long long
using namespace std;
signed main(){
	int n;
	cin>>n;
	vector<int> a;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		a.pb(x);
	}
	bool fl = true;
	for(int i=0;i<n-1;i++){
		if( a[i] >= a[i+1] ){
			fl = false;
		}
	}
	if( fl == true ){
		cout<<1<<endl;
		return 0;
	}
	int ng = 1, ok = n;
	while( ok - ng > 1 ){
		int m = (ok+ng)/2;
		//cout<<"m= "<<m<<endl;
		unordered_map<int,int> mope;
		stack<int> exist;
		int last = -1;
		bool isok = true;
		for(int i=0;i<n;i++){
			if( last < a[i] ){
				last = a[i];
				exist.push(a[i]);
			}
			else if( last == a[i] ){
				mope[last] ++ ;
			}
			else{
				while( !exist.empty() && exist.top() > a[i] ){
					mope[ exist.top() ] = 0;
					exist.pop();
				}
				mope[a[i]]++;
				exist.push(a[i]);
				last = a[i];
			}
			if( mope[last] == m ){
				while( mope[last] == m && last > 0){
					mope[last] = 0;
					last--;
					mope[last] += 1;
				}
				while( !exist.empty() && exist.top() > last){
					exist.pop();
				}
			}
			//for(int j=1;j<=last;j++){cout<<mope[j]<<" ";}cout<<endl;
			if( mope[0] != 0 ){
				isok = false;
				break;
			}
		}
		if(isok == true){
			ok = m;
		}
		else{
			ng = m;
		}
	}
	cout<< ok << endl;
	return 0;
}