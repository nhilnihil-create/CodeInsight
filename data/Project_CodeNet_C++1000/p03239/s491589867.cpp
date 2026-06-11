#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
//二項係数の計算
int nCr(int A, int B) {
    ll ans = 1;
    for (int i = 0; i < B; i++) {
        ans *= A - i;
    }
    for (int i = 0; i < B; i++) {
        ans /= i + 1;
    }
    return ans;
}
int main() {
    int N,T;
    cin>>N>>T;
    vector<int>C(N);
    vector<int>t(N);
    int ans=0;
    rep(i,N){
        cin>>C.at(i);
        cin>>t.at(i);
        if(t.at(i)<=T){
            if(ans==0){
                ans=C.at(i);
            }
            else if(C.at(i)<ans){
                ans=C.at(i);
            }
        }
    }
    if(ans==0){
        cout<<"TLE"<<endl;
    }
    else{
        cout<<ans<<endl;
    }
}