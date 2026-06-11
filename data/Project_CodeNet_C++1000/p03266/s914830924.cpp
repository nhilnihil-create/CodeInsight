#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define all(x) begin(x), end(x)
typedef long long ll;
typedef pair<int, int> pii;
const int inf=1010001000;
const ll  INF=1001000100010001000;
const int mod=(int)1e9+7;

long long Pow(long long x, long long n) {
    long long ret = 1;
    while (n > 0) {
        if (n & 1) ret *= x;  // n の最下位bitが 1 ならば x^(2^i) をかける
        x *= x;
        n >>= 1;  // n を1bit 左にずらす
    }
    return ret;
}

int main(){
    int n,k;
    cin>>n>>k;
    vector<int>m(k);
    rep(i,1,n+1){
        m.at(i%k)++;
    }
    if(k%2==1){
        cout<<Pow(m.at(0),3)<<endl;
        return 0;
    }
    else{
        cout<<Pow(m.at(0),3)+Pow(m.at(k/2),3)<<endl;
    }
return 0;
}