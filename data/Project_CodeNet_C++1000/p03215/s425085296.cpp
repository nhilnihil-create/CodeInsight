#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rrep(i,n) for(int (i)=((n)-1);(i)>=0;(i)--)
#define itn int
#define all(x) (x).begin(),(x).end()
const long long INF = 1LL << 60;
const int MOD = 1000000007;
int n,k;
void cur(int bit, vector <int> b, int ma){
    //cout<<bit<<endl;
    int c = 1LL<<(bit);
    int sz = b.size();
    vector <int> tmp; 
    rep(i,sz){
        if(b[i]&c) tmp.push_back(b[i]);
    }
    if(bit == 0) {
        if(tmp.size()>=k) ma|=1; 
        cout<<ma<<endl;
        exit(0);
    }
    if(tmp.size()>=k) cur(bit-1, tmp, ma+c);
    else cur(bit-1, b, ma);
}
signed main(void){
    cin>>n>>k;
    vector <int> a(n); 
    rep(i,n) cin>>a[i];
    vector <int> sum(n+1); 
    rep(i,n) sum[i+1] = sum[i] + a[i];
    vector <int> b; 
    rep(i,n) for(int j=i+1;j<=n;j++) b.push_back(sum[j] - sum[i]);
    
    sort(b.begin(),b.end(),greater <int>());
    
    cur(60, b, 0);
}
