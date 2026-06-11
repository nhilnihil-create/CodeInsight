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
    int d,g;cin >> d >> g;
    vector<int> a(d);
    vector<int> b(d);
    REP(i,d)cin >> a[i] >> b[i];
    
    int ans = INF;
    for(int bit=0;bit<(1<<d);bit++){
        int count=0,score=0;
        for(int i=0;i<d;i++){
            if(bit&(1<<i)){
                count+=a[i];
                score+=(100*(i+1)*a[i]+b[i]);
            }
        }
        if(score>=g)ans = min(ans,count);
        else{
            for(int i=d-1;i>=0;i--){
                if(bit&(1<<i))continue;
                for(int j=0;j<a[i];j++){
                    if(score>=g)break;
                    count++;
                    score+=100*(i+1);
                }
            }
            ans = min(ans,count);
        }
    }
    COUT(ans);
    return 0;
}