#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep2(i,s,n) for(int i=(s);i<(int)(n);i++)
typedef long long ll;

int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i,N) cin >> A[i];
    vector<ll> cnt(4000001);
    bitset<4000001> dp;
    bitset<4000001> dp_shifted;
    dp.set(0);
    rep(i,N){
        dp_shifted = dp << A[i];
        dp |= dp_shifted;
    }

    double sum =0;
    rep(i,N){
        sum+=A[i];
    }
    
    rep2(i,(int)((sum+1)/2),4000001){
        if(dp.test(i)){
            cout << i << endl;
            break;
        }
    }
}