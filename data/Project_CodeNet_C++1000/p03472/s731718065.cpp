#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
using pint = pair<int, int>;
using pll = pair<ll,ll>;

const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) for(int i=0;i<(n);++i)
#define COUT(x) cout<<(x)<<"\n"

int main(){
    int n,h;
    cin >> n >> h;
    vector<int>b(n+1,0);
    int cut_max=0,a;
    REP(i,n){
        cin >> a >> b[i];
        cut_max = max(a,cut_max);
    }
    sort(b.begin(),b.end(),greater<>());
    int index=0,count=0;
    while(h>0){
        if(cut_max<b[index]){
            h-=b[index];
            index++;
            count++;
        }
        else{
            count += (h+cut_max-1)/cut_max;
            break;
        }
    }
    COUT(count);
    return 0;
} 