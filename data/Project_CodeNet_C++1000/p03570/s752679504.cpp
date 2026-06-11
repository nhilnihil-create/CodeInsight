#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

const int MAXN=200010;
string ss;
unordered_map<int, int> myhash;

int getmin(int stat) {
	int ans=MAXN;
	if (stat == 0)
		return 0;
	//zero 
	auto fd0 = myhash.find(stat);
	if (fd0 != myhash.end())
		ans = fd0->second;
	//stat^prev^stat = (1<<i)^stat
	for (int i=0;i<26;i++) {//'a'+i
		if ( (stat^(1<<i)) == 0 )//self par.
			return 0;
		auto fd=myhash.find(stat^(1<<i));
		if (fd != myhash.end())
			ans = min(ans, fd->second);
	}
	return ans;
}

int main() {
	cin>>ss;
	int dp;
	for (int i=0,stat=0; i<ss.length(); i++) {
		//cout<<"Pos "<<i<<endl;
		stat ^= 1<<(ss[i]-'a');
		dp = getmin(stat)+1;
		auto fd = myhash.find(stat);
		if (fd==myhash.end() || fd->second>dp)
			myhash[stat]=dp;
		//cout<<"<Result> HereStat="<<stat<<“ dp[i]="<<dp[i]<<endl<<endl;
	}
	cout<<dp<<endl;
	return 0;
}
