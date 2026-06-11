#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep2(i,s,n) for(int i=(int)(s);i<(int)(n);i++)
typedef long long ll;
const int INF = 1e+9+7;

int main(){
    ll N,K,ans,num;
    cin >>N >> K;
    if(K%2!=0){
        num=N/K;
        ans = pow(num,3);
    }else{

        num=(N/(K/2))/2;
        ans = pow(num,3);
        num=N/(K/2) -num;
        ans += pow(num,3);
    
    }
    cout << ans << endl;

}
