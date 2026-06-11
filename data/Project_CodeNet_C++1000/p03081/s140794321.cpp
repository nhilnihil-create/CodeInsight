#include <bits/stdc++.h>
 
using namespace std;
 
#define lli long long int
#define REP(i,s,l) for(lli i=s;i<l;i++)
#define DEBUG 0
#define INF (1LL<<50)
#define MOD 1000000007

signed main(){

	lli n,q;
	cin>>n>>q;
	string s;
	cin>>s;

	vector<char> t(q),d(q);
	REP(i,0,q)cin>>t[i]>>d[i];

	/*左から落ちる人と右から落ちる人の動きを再現させる。*/
	/*この時左から落ちる人は一番どこにいうるか？*/

	lli left=0;
	lli right=n-1;

	/*leftを動かす*/
	for(lli i=q-1;i>=0;i--){
		if(left>=n)break;
		char nowPos = s[left];
		if(t[i]==nowPos && d[i] == 'L')left++;
		if(left>0 && s[left-1] == t[i] && d[i] =='R')left--;
	}

	for(lli i=q-1;i>=0;i--){
		if(right<0)break;
		char nowPos = s[right];
		if(t[i]==nowPos && d[i] == 'R')right--;
		if(right<n-1 && s[right+1] == t[i] && d[i] == 'L')right++;
	}
	if(DEBUG)cout<<"left="<<left<<" right="<<right<<endl;
	cout<<max(0LL,right - left +1)<<endl;

	return 0;
}