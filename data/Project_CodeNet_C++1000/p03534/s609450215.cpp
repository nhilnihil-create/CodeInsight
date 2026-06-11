#include <bits/stdc++.h>
typedef long long ll;
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,a) FOR(i,0,a)

using namespace std;
string S;
int cnt[3],ans[3];
int main(){
	cin>>S;
	int n=(int)S.size();
	REP(i,n){
		cnt[S[i]-'a']++;
	}
	sort(cnt,cnt+3);
	REP(i,3){
		ans[i]=n/3+(n%3>i);
	}
	sort(ans,ans+3);
	bool f=true;
	REP(i,3){
		f&=cnt[i]==ans[i];
	}
	cout<<(f ? "YES" :"NO")<<endl;
}