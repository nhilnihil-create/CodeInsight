#include <bits/stdc++.h>

using namespace std;

#define lli long long int
#define REP(i,s,n) for(int i=s;i<n;i++)
#define MOD 1000000007
#define NUM 2520
#define INF (1LL<<50)
#define DEBUG 0
#define mp(a,b) make_pair(a,b)
#define SORT(V) sort(V.begin(),V.end())
#define PI (3.141592653589794)

signed main(){

	string s;
	cin>>s;

	lli left=0,right=s.size()-1;
	lli cnt=0;
	while(left<right){
		if(s.at(left)==s.at(right)){
			left++;
			right--;
			continue;
		}
		if(s.at(left)=='x'){
			left++;
			cnt++;
			continue;
		}
		if(s.at(right)=='x'){
			right--;
			cnt++;
			continue;
		}
		cout<<-1<<endl;
		return 0;
	}
	cout<<cnt<<endl;

	return 0;
}