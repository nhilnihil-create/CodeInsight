#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
int gg=1;
int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int m,k;cin>>m>>k;
	if(m==0&&k==0){
		cout<<"0 0";return 0;
	}
	if(m==1&&k==0){
		cout<<"0 0 1 1";return 0;
	}else if(m==1&&k!=0){
		cout<<-1;return 0;
	}
	for(int i=0;i<m;i++){
		gg*=2;
	}
	if(k>=gg){
		cout<<-1;return 0;
	}
	cout<<k<<' ';
	for(int i=0;i<=gg-1;i++){
		if(i==k)continue;
		cout<<i<<' ';
	}cout<<k<<' ';
	for(int i=gg-1;i>=0;i--){
		if(i==k)continue;
		cout<<i<<' ';
	}
	return 0;
}