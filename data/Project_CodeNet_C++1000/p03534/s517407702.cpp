#include <bits/stdc++.h>
#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define RREP(i,a,b) for(int i=(a);i>=(b);i--)
#define pq priotity_queue
#define P pair<int,int>
#define P2 pair<int,P>
#define P3 pair<int,P2>
typedef long long ll; typedef long double ld;
using namespace std;
const int INF=1e9, MOD=1e9+7, around[]={0,1,1,-1,-1,0,-1,1,0,0};
const ll LINF=1e18;
const ld PI=abs(acos(-1));
int li[5];
string s;

int main(){
	cin >> s;
	REP(i,0,s.size()) li[s[i]-'a']++;
	sort(li,li+3);
	
	bool f=(max(li[1]-li[0], max(li[2]-li[1], li[2]-li[0]))<=1);
	cout << (f?"YES":"NO") << endl;
	return 0;
}
