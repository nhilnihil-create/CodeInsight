#include "bits/stdc++.h"

#define REP(i, n, N) for(ll i=(n); i<(N); i++)
#define RREP(i, n, N) for(ll i=(N-1); i>=n; i--)
#define CK(n, a, b) ((a)<=(n)&&(n)<(b))
#define ALL(v) (v).begin(),(v).end()
#define MCP(a, b) memcpy(b,a,sizeof(b))
#define p(s) cout<<(s)<<endl
#define p2(a, b) cout<<(a)<<" "<<(b)<<endl
#define v2(T) vector<vector<T>>
typedef long long ll;
using namespace std;
const ll mod = 1e9 + 7;
const ll inf = 1e18;


ll N;
ll k;
ll start[100010];
int main() {
    cin>>N;
    ll po=0;
    bool f=false;
    ll cnt=0;
    REP(i,1,N+1){
        po+=i;
        if(po==N){
            f=true;
            k=i;
            break;
        }
    }
    if(N==1){
        p("Yes");
        cout<<2<<endl;
        cout<<"1 1"<<endl;
        cout<<"1 1"<<endl;
    }else if(f){
        p("Yes");
        cout<<k+1<<endl;
        start[0]=1;
        REP(i,1,k+2){
            start[i]=start[i-1]+k-i+1;
        }
        REP(i,0,k+1){
            cout<<k;
            REP(j,0,i){
                cout<<" "<<start[j]+(i-j)-1;
            }
            REP(j,0,k-i){
                cout<<" "<<start[i]+j;
            }
            cout<<endl;
        }


    }else{
        p("No");
    }
    return 0;
}
