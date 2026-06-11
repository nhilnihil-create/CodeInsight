#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define numrep(i,n) for(int i=1;i<=n;i++)
#define bitrep(n) for(int bit=0;bit<(1<<n);bit++)
#define ll int64_t
#define all(v) v.begin(), v.end()

const int MOD = 1000000007;

int main() {

string S; cin>>S;

if(S[5]=='1') cout << "TBD" << endl;

else if(S[6]-'0'<=4) cout << "Heisei" << endl;

else cout << "TBD" << endl;

return 0;
}