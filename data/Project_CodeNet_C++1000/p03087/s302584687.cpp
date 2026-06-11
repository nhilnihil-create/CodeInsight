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
#include <iomanip>
#include <unordered_map>
#include <map>
#include <boost/multiprecision/cpp_int.hpp>

#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define rep1(i,n) for(int i=1, i##_len=(n); i<=i##_len; ++i)
#define reps(i,s,n) for(int i=s, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define MEMSET(v, h) memset((v), h, sizeof(v))
typedef long long ll;
typedef long double ld;
const char sp = ' ';

using namespace boost::multiprecision;
using namespace std;

int main(void){
    ll N, Q;
    string S;
    cin>>N>>Q>>S;
    ll l, r;
    ll L[200000], R[200000];
    ll flag=0;
    L[0]=0;
    R[0]=0;
    rep1(i, N){
        bool changedr=false, changedl=false;
        if(i!=1) if(S[i-2]=='A' && S[i-1]=='C'){
            R[i]=R[i-1]+1; changedr=true;
        }
        if(i!=N-1) if(S[i-1]=='A' && S[i]=='C'){
            L[i]=L[i-1]+1; changedl=true;
        }
        if(!changedr) R[i]=R[i-1];
        if(!changedl) L[i]=L[i-1];
        //cout<<L[i]<<sp<<R[i]<<endl;
    }
    rep(i, Q){
        ll l, r;
        cin>>l>>r;
        cout<<R[r]-L[l-1]<<endl;
    }
    return 0;
}
