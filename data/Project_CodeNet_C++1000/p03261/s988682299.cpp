#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = 1; i < (int)(n+1); i++)
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
// vector<vector<int>> A(3, vector<int>(4));
int main() {
    int N;
    cin>>N;
    vector<string>W(N);
    bool  ans=true;
    rep(i,N){
        cin>>W[i];
        if(i!=0){
            string H=W[i];
            string J=W[i-1];
            if(J[J.size()-1]!=H[0]){
                ans=false;
            }
        }
    }
    sort(W.begin(),W.end());
    rep(i,N){
        if(i!=0){
            if(W[i]==W[i-1]){
                ans=false;
            }
        }
    }
    if(ans==true){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
}
