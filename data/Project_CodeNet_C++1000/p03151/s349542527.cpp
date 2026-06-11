#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) for(int i=0;i<(n);++i)
#define REPR(i,n) for(int i=n;i>=0;i--)
#define ALL(v) ((v).begin(),(v).end())
#define COUT(x) cout<<(x)<<"\n"

int main(){
    int n;cin >>n;
    vector<int> a(n),b(n);
    ll sum_a=0,sum_b=0;
    REP(i,n){
        cin >> a[i];
        sum_a+=a[i];
    }
    REP(i,n){
        cin >> b[i];
        sum_b+=b[i];
    }
    int ans=0;
    if(sum_a<sum_b)ans=-1;
    else{
        vector<int> diff;
        ll sum_diff=0;
        REP(i,n){
            if(a[i]<b[i]){
                sum_diff+=(b[i]-a[i]);
                ans++;
            }
            else if(a[i]>b[i]){
                diff.push_back(a[i]-b[i]);
            }
        }
        sort(diff.begin(),diff.end(),greater<>());
        if(ans!=0){
            for(int x:diff){
                sum_diff-=x;
                ans++;
                if(sum_diff<=0)break;
            }
        }
    }
    COUT(ans);
    return 0;
}