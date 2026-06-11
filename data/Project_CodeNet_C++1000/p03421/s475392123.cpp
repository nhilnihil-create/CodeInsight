#include <bits/stdc++.h>
typedef long long ll;
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,a) FOR(i,0,a)
	
using namespace std;
const int MAX_N=3e5,INF=1e8;
int N,A,B;
vector<int> ans;
int main(){
	bool f=false;
	cin>>N>>A>>B;
	if (A>B){
		f=true;
		swap(A,B);
	}
	if ((ll)N<=(ll)A*B && A+B<=N+1){
		int b=0;
		REP(i,N){
			if (N-i+b==B){
				FOR(j,i,N){
					ans.push_back(-INF-j);
				}
				break;
			}else{
				if (i%A==0){
					b++;
				}
				ans.push_back(-A*b+i%A);
			}
		}
		{
			vector<int> x(ans);
			sort(x.begin(),x.end());
			REP(i,N){
				ans[i]=lower_bound(x.begin(),x.end(),ans[i])-x.begin()+1;
			}
		}
		if (f){
			reverse(ans.begin(),ans.end());
		}
		REP(i,N){
			if (i)cout<<" ";
			cout<<ans[i];
		}
		cout<<endl;
	}else{
		cout<<-1<<endl;
	}
	return 0;
}