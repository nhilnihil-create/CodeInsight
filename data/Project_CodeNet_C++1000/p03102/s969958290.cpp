#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i < (n); i++)
using namespace std;
using ll = long long;


int main(){
    int N,M,C;
    cin >> N >> M >> C;
    
    vector<int> B(M);
    rep(i,M){
        cin >> B[i];
    }
    
    int ans=0;
    rep(z,N){
        int sum=0;
        rep(i,M){
            int x;
            cin >> x;
            sum += x * B[i];
        }
        if(sum + C >0){
            ans++;
        }
    }
    
    cout << ans << endl;
}
