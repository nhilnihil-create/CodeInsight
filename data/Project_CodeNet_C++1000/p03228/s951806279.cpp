#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) for(int i=0;i<(n);++i)
#define REPR(i,n) for(int i=n;i>=0;i--)
#define ALL(v) (v.begin(),v.end())
#define COUT(x) cout<<(x)<<endl

int main(){
    int a,b,k;
    cin >> a >> b >> k;
    int count = 0;
    while(count!=k){
        if(count%2==0){
            if(a%2!=0) a-=1;
            a /= 2;
            b += a;
        }
        else{
            if(b%2!=0) b-=1;
            b /= 2;
            a += b;
        }
        count++;
    }
    printf("%d %d",a,b);
    return 0;
}    