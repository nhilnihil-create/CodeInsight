#include <bits/stdc++.h>
typedef long long ll;
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,a) FOR(i,0,a)
	
using namespace std;
const int MAX_K=1e4;
vector<int> vec[MAX_K];
int main(){
	int N;
	cin>>N;
	int ans;
	bool flg=false;
	FOR(k,1,1e4+1){
		if (k*(k-1)==2*N){
			flg=true;
			ans=k;
			int cnt=1;
			REP(i,k){
				FOR(j,i+1,k){
					vec[i].push_back(cnt);
					vec[j].push_back(cnt);
					cnt++;
				}
			}
			break;
		}
	}
	if (flg){
		cout<<"Yes"<<endl<<ans<<endl;
		REP(i,ans){
			cout<<vec[i].size();
			for(auto ite:vec[i]){
				cout<<" "<<ite;
			}
			cout<<endl;
		}
	}else{
		cout<<"No"<<endl;
	}
	return 0;
}