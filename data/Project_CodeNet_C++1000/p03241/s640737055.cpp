#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <utility>
#include <set>
#include <stack>
#include <climits>
#include <cmath>

#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define rep1(i,n) for(int i=1, i##_len=(n); i<=i##_len; ++i)
#define reps(i,s,n) for(int i=s, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define MEMSET(v, h) memset((v), h, sizeof(v))
typedef long long ll;
const char sp = ' ';


using namespace std;

vector<ll> yakusu;

int main(void){
    ll N, M, Maxim=1;
    cin>>N>>M;
    rep1(i, sqrt(M)){
        if(M%i==0){
            if(i*N<=M) Maxim=max(Maxim, (ll)i);
            if((M/i)*N<=M) Maxim=max(Maxim, (ll)(M/i));
        }
    }
    cout<<Maxim<<endl;
    return 0;
}
