#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    int n;
    cin >> n;
    vector<ll> v(5);
    rep(i,n){
        string s;
        cin >> s;
        if(s.front()=='M') v[0]++;
        if(s.front()=='A') v[1]++;
        if(s.front()=='R') v[2]++;
        if(s.front()=='C') v[3]++;
        if(s.front()=='H') v[4]++;
    }
    ll ans = 0;
    for(int i=0; i<5; i++){
        for(int j=i+1; j<5; j++){
            for(int k=j+1; k<5; k++){
                ans += v[i]*v[j]*v[k];
            }
        }
    }
    cout << ans << endl;
    return 0;
}