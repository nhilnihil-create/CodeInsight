#include <bits/stdc++.h>
using namespace std;

#define All(v) (v).begin(),(v).end()
int dy[8] = {-1,0,1,0,-1,1,1,-1};
int dx[8] = {0,1,0,-1,1,1,-1,-1};
const int mod = 1000000007;

long long pow(long long x,long long n){
    long long res=1;
    while(n>0){
        if(n&1)res*=x;
        x*=x;
        n/=2;
    }
    return res;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,k;
    cin>>n>>k;
    vector<long long> a(n+1,0);
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)a[i]+=a[i-1];
    vector<long long> v;
    for(int i=0;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            v.push_back(a[j]-a[i]);
        }
    }

    long long res=0;
    for(int bit=50;bit>=0;bit--){
        int cnt=0;
        for(auto it:v){
            if(it&(1ll<<bit))cnt++;
        }
        if(cnt>=k){
            res+=pow(2,bit);
            vector<long long> vv;
            for(auto it:v){
                if(it&(1ll<<bit))vv.push_back(it);
            }
            v=vv;
        }
    }
    cout<<res<<endl;
}
