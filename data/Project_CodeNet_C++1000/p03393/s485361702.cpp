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

lli data[26];

signed main(){

	string s;
	cin>>s;
	REP(i,0,s.size())data[s.at(i)-'a']++;

	REP(i,0,26){
		if(data[i]==0){
			cout<<s<<(char)('a'+i)<<endl;
			return 0;
		}
	}
	if(s=="zyxwvutsrqponmlkjihgfedcba")cout<<-1<<endl;
	else
	{
		string t=s;
		next_permutation(s.begin(),s.end());
		REP(i,0,s.size()){
			cout<<s[i];
			if(t[i]!=s[i]){
				cout<<endl;
				return 0;
			}
		}
	}

	return 0;
}