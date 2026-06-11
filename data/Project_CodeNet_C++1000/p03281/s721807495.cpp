#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using vi = vector<int>;
using vv = vector<vi>;

const int MOD = 1000000007;
const int INF = 1001001001;

int main(){
    int n;cin>>n;
    
    int ans = 0;
    
    for(int i=3; i<=n; i+=2){
        int count = 0;
        for(int j=1; j<=i; j++){
            if(i%j==0)count++;
        }
        if(count==8)ans++;
    }
    
    cout << ans << endl;
    return 0;
}