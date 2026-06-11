#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define forin(in, n) for(int i=0; i<n; i++) cin>>in[i]
#define forout(out) for(int i=0; i<(int)out.size(); i++) cout<<out[i]<<" "
#define rep(i, n) for(int i=0; i<(n); i++)

int digit_sum(int n){
    int ans=0;
    while(1 == 1){
        ans += n%10;
        n/=10;
        if(n==0) break;
    }
    return ans;
}


int main(){
    int n, a, b; cin>> n >> a >> b;
    int ans=0;
    for(int i=1; i<=n; i++){
        int sum=digit_sum(i);
        if(sum >= a && sum <= b) ans += i;
    }
    cout << ans << endl;
}