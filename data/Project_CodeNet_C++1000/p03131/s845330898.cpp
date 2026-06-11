#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

const int INF=1e9;
const int MOD=1e9+7;

int main(){
    ll k,a,b; cin >> k >> a >> b;
    ll ans;
    if(a+1<b){
        ll cnt=a-1;
        k-=cnt;
        ans=(k/2)*(b-a)+k%2+a;
    }else{
        ans=k+1;
    }
    cout << ans << endl;
}