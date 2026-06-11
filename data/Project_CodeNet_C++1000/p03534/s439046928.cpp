#include <bits/stdc++.h>
#define p(s) cout<<(s)<<endl
#define REP(i,n,N) for(int i=n;i<N;i++)
#define RREP(i,n,N) for(int i=N-1;i>=n;i--)
#define CK(n,a,b) ((a)<=(n)&&(n)<(b))
#define F first
#define S second
typedef long long ll;
using namespace std;
const int inf = 1e9;

int a[3];
string s;

int main() {
    cin>>s;
    REP(i,0,s.size()){
        if(s[i]=='a') a[0]++;
        else if(s[i]=='b') a[1]++;
        else a[2]++;
    }
    sort(a,a+3);
    if(a[2]-a[0]<=1){
        p("YES");
    }else p("NO");
	return 0;
}
