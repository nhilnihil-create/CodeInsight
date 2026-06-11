#include <bits/stdc++.h>
#define mod 1000000007
#define pb push_back
#define ll long long
#define mp make_pair
using namespace std;
vector<int> pl[200009];
int main(){
	int h,w,n,aom=1;
	cin>>h>>w>>n;
	for(int i=0;i<200008;i++){
		pl[i].pb(w+1);
	}
	for(int i=0;i<200008;i++){
		pl[h+1].pb(i);
	}
	for(int i=0;i<n;i++){
		int x,y;
		cin>>x>>y;
		pl[x].pb(y);
	}
	for(int i=1;i<200008;i++){
		sort(pl[i].begin(),pl[i].end());
	}
	for(int i=1;i<200008;i++){
		if(pl[i+1][0]<=aom){
			cout<<i<<endl;
			return 0;
		}
		else{
			int fl = 0;
			for(int j=0;j<pl[i+1].size();j++){
				if(aom+1 == pl[i+1][j])fl = 1;
			}
			if(fl==0)aom++;
		}
	}
	return 0;
}