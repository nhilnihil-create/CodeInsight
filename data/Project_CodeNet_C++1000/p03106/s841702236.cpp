#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define sz(x) int(x.size())
#define pb push_back
#define eb emplace_back
using ll=long long;
using P = pair<int,int>;
using LP=pair<ll,int>;
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)
const ll MOD=1000000007,MOD2=998244353;



int main() {
    int A,B,C;
    cin>>A>>B>>C;
    int count=0;
    for(int i=101;i>=1;i--){
        if(A%i==0 && B%i==0){
            count++;
        }
        if(count==C){
            cout<<i<<endl;
            return 0;
        }
    }
}