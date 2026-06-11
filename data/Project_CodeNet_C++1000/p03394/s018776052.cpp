#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,n) for (int i=0;i<(n);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)
typedef long long LL;
int N;
vector<int>v;
vector<int>w;
vector<int>x;
int main(){
	cin>>N;
	if(N==3){
		cout<<2<<" "<<5<<" "<<63<<endl;
	}else if(N==4){
		cout<<2<<" "<<5<<" "<<20<<" "<<63<<endl;
	}else{
		vector<int>ans;
		if(N%2==1){
			ans.push_back(6);
		}
		ans.push_back(3);
		ans.push_back(9);
		REP(i,30001){
			if(i==0)continue;
			if(i%2==0&&i%3!=0){
				ans.push_back(i);
			}
		}
		//cout<<ans.size()<<endl;
		REP(i,30001){
			if(i==0)continue;
			if(i==3)continue;
			if(i==9)continue;
			if(i%3==0&&i%2!=0){
				ans.push_back(i);
			}
		}
		REP(i,30001){
			if(i==0)continue;
			if(i==6)continue;
			if(i%6==0){
				ans.push_back(i);
			}
		}
		ans.push_back(6);
		//cout<<ans.size()<<endl;
		REP(i,N){
			cout<<ans[i];
			if(i==N-1){
				cout<<endl;
			}else{
				cout<<" ";
			}
		}
	}
	return 0;
}