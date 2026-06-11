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

int main(void){
    ll N, A[10900], B[10900], acou=0, bcou=0;
    cin>>N;
    rep(i, N) cin>>A[i];
    rep(i, N) cin>>B[i];
    rep(i, N){
        ll a=A[i];
        ll b=B[i];
        if(a>b) bcou+=a-b;
        else{
            if(a%2==b%2) acou+=(b-a)/2;
            else acou+=(b-a+1)/2, bcou++;
        }
        //cout<<acou<<sp<<bcou<<endl;
    }
    cout<<(acou>=bcou ? "Yes" : "No")<<endl;
    return 0;
}
