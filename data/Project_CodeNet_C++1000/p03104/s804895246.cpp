#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9+7;
struct edge{ll x,y;};
struct huga{ll honest; bool done;};
using namespace std;

vector<int>binary(ll temp){
    vector<int>s;
        while(temp){
            temp--;
            s.push_back(temp%2);
            temp = temp / 2;
        }
    return s;
}

ll calc(ll n){
    if((n+1) % 2 == 0){
      return (( n+ 1) / 2) % 2;
    }
    else{
        int cntone = (n/2)%2;
        return cntone ^ n;
        }

}




int main(){
    ll a,b;
    cin >> a >> b;
    ll ans;
    ans = calc(b) ^ calc(a-1);
    cout << ans << endl;

    
}