#include<bits/stdc++.h>
using namespace std;
int main(){
    long long int n,k;
    cin >> n >> k;
    long long int ans=0;
    for(long long int i=k+1;i<=n;i++){
        if(k==0){
            ans += n/i;
            long long int mod = min((n+i-1)%i+1,i-1);
            if(i>1)ans += (((n+i-1)/i)*mod+(((n+i-1)/i-1)*(i-mod-1)));
        }
        else{
            int mod = min((n+i-k)%i+1,i-k);
            ans += ((n+i-k)/i)*(mod)+(((n+i-k)/i-1)*(i-k-mod));            
        }
    }
    cout << ans << endl;
}