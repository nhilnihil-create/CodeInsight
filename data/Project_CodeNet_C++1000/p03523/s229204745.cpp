#include <iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<math.h>
using namespace std;
typedef long long ll;
typedef vector<int> VI;
#define REP(i,n) for(int i=0;i<n;i++)
#define eREP(i,n) for(int i=0;i<=n;i++)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define eFOR(i,a,b) for(int i=(a);i<=(b);++i)
#define SORT(c) sort((c).begin(),(c).end())
#define rSORT(c) sort((c).rbegin(),(c).rend())
#define LB(x,a) lower_bound((x).begin(),(x).end(),(a))
#define UB(x,a) upper_bound((x).begin(),(x).end(),(a))
#define INF 1000000000
#define LLINF 9223372036854775807
#define mod 1000000007
//vector<vector<int> > dp;
//vector<vector<vector<int> > > vvvi;
//dp=vector<vector<int> >(N, vector<int>(M,0));
//vector<pair<int,int> > v;
//v.push_back(make_pair(x,y));

int main(){
cin.tie(0);
ios::sync_with_stdio(false);

	string S;
	cin>>S;
	string A="KIHBR";
	int j=0;
	if(S.size()>9){
			cout<<"NO"<<endl;
			return 0;
	}
	REP(i,S.size()){
		//cout<<i<<" "<<j<<endl;
		if(S[i]==A[j])j++;
		else if(S[i]=='A' && i==0)continue;
		else if(S[i]=='A' && S[i-1]!='A' && j!=1 && j!=2)continue;
		else{
			cout<<"NO"<<endl;
			return 0;
		}
		
	}
	if(j!=5)
		cout<<"NO"<<endl;
	else 
		cout<<"YES"<<endl;
	
	return 0;
}
