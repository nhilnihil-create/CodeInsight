#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
using ll=long long;
using P = pair<int,int>;
int main(){
    int N,X;
    cin >> N >>X;
    int m=1001;
    int sum=0;
    rep(i,N){
        int a;
        cin >> a;
        m=min(m,a);
        sum+=a;
    }
    X=X-sum;
    int ans = N;
    ans+=X/m;
    cout << ans << endl;
}
