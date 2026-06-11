#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007 

ll op[100][10],n,pro[100][11],jo[10],ans=-1*INF;

void cal(){
	bool ex=true;
	for(ll i=0;i<10;i++){
		if(jo[i]){
			ex=false;
		}
	}
	if(ex){
		return;
	}
	//cout << "k";
	ll sum=0;
	for(ll i=0;i<n;i++){
		ll cnt=0;
		for(ll j=0;j<10;j++){
			if(jo[j]==1&&op[i][j]==1){
				cnt++;
			}
		}
		sum+=pro[i][cnt];
	}
	ans=max(sum,ans);
}
void dep(ll now){
	if(now==10){
		cal();
		return ;
	}
	jo[now]=1;dep(now+1);
	jo[now]=0;dep(now+1);
}
int main() {
	cin>>n;
	for(ll i=0;i<n;i++){
		for(ll j=0;j<10;j++){
			cin>>op[i][j];
		}
	}
	for(ll i=0;i<n;i++){
		for(ll j=0;j<=10;j++){
			cin>>pro[i][j];
		}
	}
	//cout << pro[0][6];
	dep(0);
	cout <<ans;
	// your code goes here
	return 0;
}