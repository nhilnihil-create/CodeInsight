#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    ll A,B,K;
    cin >> A >> B >> K;
  	ll e=min(A+K,max(1LL,B-K+1));
    rep(i,A,e){
        cout<<i<<endl;
    }
  	ll s=max(A,max(1LL,B-K+1)); 
    rep(i,s,B+1){
        cout<<i<<endl;
    }
    return 0;
}