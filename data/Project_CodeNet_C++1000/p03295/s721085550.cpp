#include<bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for(int i=x;i<y;i++)
#define print(A,x,n) rep(i,0,n){cout<<(i ? " ":"")<<A[i]x;}cout<<endl;
#define pprint(A,y,m,n) rep(j,0,m){print(A[j],y,n);}
const long mod=1e9+7;
const int size=2e5;
const int inf=1e9;
int main(){
	int N,M;cin>>N>>M;
	vector<pair<int,int>> vp(M);
	rep(i,0,M){
        cin>>vp[i].first>>vp[i].second;
        vp[i].first--;
        vp[i].second--;
    }
	sort(vp.begin(), vp.end());
	int e = N-1; int cnt = 0;
	for(int i = M-1; i >= 0; i--){
		if(vp[i].second <= e){
			e = vp[i].first;
			cnt++;
		}
	}cout<<cnt<<endl;
}