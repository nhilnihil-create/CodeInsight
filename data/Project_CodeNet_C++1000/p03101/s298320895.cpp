#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define numrep(i,n) for(int i=1;i<=n;i++)
#define bitrep(n) for(int bit=0;bit<(1<<n);bit++)
#define ll int64_t
#define all(v) v.begin(), v.end()

const int MOD = 1000000007;

int main() {

int H,W; cin>>H>>W;

int h,w; cin>>h>>w;

cout << (H-h)*(W-w) << endl;


return 0;
}