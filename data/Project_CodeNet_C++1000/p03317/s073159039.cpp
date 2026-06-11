#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep2(i,s,n) for(int i=(int)(s);i<(int)(n);i++)
typedef long long ll;
const int INF = 1e+9+7;

int main(){
    double N,K;
    cin >> N >> K;
    vector<int> A(N);
    double i_min;
    rep(i,N){
        cin >> A[i];
        if(A[i]==1) i_min=i+1;
    }

    int r;
    int ans=INF;
    rep(l,K){
        r=K-1-l;
        ans=min(ans,1+max(0,(int)ceil((i_min-1-l)/(K-1)))+max(0,(int)ceil((N-i_min-r)/(K-1))));
    }
    cout << ans << endl;

}
