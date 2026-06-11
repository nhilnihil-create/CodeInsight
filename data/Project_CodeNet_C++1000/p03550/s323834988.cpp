#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;


int main(){
    ll n, z, w;
    cin >> n >> z >> w;
    vector<ll> card(n);
    for(int i = 0; i < n; ++i){
        cin >> card.at(i);
    }
    ll ans = abs(card.at(n - 1) - w);
    if(n > 1){
        ans = max(ans, abs(card.at(n - 1) - card.at(n - 2)));
    }
    cout << ans << endl;
    return 0;
}