#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = 1; i < (int)(n + 1); i++)
// vector<vector<int>> A(3, vector<int>(4));
int main() {
    int N,K;
    cin>>N>>K;
    vector<int>A(N);
    vector<int>B(300000);
    rep(i,N){
        cin>>A[i];
        B[A[i]]++;
    }
    int cnt=0;
    sort(B.begin(),B.end());
    rep(i,300000){
        if(B[i]!=0){
            cnt++;
        }
    }
    cnt=cnt-K;
    ll ans=0;
    rep(i,300000){
        if(cnt<=0){
            break;
        }
        else{
            if(B[i]!=0){
                ans+=B[i];
                cnt--;
            }
        }
    }
    cout<<ans<<endl;
}

