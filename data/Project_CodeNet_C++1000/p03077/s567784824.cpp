#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void){
    ll n;
    cin >> n;
    vector<ll> time(5);
    for(int i=0;i<5;i++){
        cin >> time[i];
    }
    sort(time.begin(),time.end());
    ll ans = (n+time[0]-1)/time[0]+4;
    cout << ans << endl;

}