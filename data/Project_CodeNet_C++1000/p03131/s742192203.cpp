#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
int main(){
    ll k,a,b;
    ll ans=1;
    cin >> k >> a >> b;
    if(b-a > 2){
        int kaisu = max((ll)0,(k-(a-1))/2);
        int tataku = k - kaisu*2;
        ans = kaisu*(b-a) + tataku + 1;
    }
    else{
        ans = k+1;
    }
    cout << ans << endl;
}