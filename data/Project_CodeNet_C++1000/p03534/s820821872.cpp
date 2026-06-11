#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
#define pb push_back
int dy[]={0, 0, 1, -1, 1, 1, -1, -1};
int dx[]={1, -1, 0, 0, 1, -1, -1, 1};

#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,n) for (int i=0;i<(n);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)
#define mp make_pair
#define fi first
#define sc second
ll n;
char s[200000];
char cou[3];
int main(){
	cin >> s;
	n = strlen(s);

	REP(i,n) {
		cou[s[i] - 'a']++;
	}

	sort(cou,cou+3);

	cou[2] -= cou[0];

	if(cou[2] <= 1) {
		cout << "YES" << endl;
	}else {
		cout << "NO" << endl;
	}
	return 0;
}
