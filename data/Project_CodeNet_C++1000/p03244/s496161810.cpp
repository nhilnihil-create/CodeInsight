#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;

ll gcd(ll x, ll y) { return (x % y)? gcd(y, x % y): y; }


int main(){
    ll n;
    cin >> n;
    vector<ll> num(n, 0);
    vector<ll> cnt_0(1e5 + 1, 0);
    vector<ll> cnt_1(1e5 + 1, 0);

    ll ans = n;
    for(int i = 0; i < n; i++) cin >> num[i];

    for(int i = 0; i < n ; i += 2){
        cnt_0[num[i]]++;

    }

    for(int i = 1; i < n; i += 2){
        cnt_1[num[i]]++;
    }

    ll max_0 = 0;
    ll max_1 = 0;

    ll max_num_0;
    ll max_num_1;

    for(int i = 0; i < 1e5 + 1; i++){
        max_0 = max(max_0 , cnt_0[i]);
        max_1 = max(max_1 , cnt_1[i]);
        if(max_0 == cnt_0[i]){
            max_num_0 = i;
        }
        if(max_1 == cnt_1[i]){
            max_num_1 = i;
        }        
    }



    sort(cnt_0.begin(), cnt_0.end() ,greater<ll>());
    sort(cnt_1.begin(), cnt_1.end() ,greater<ll>());
    

    if(max_num_0 != max_num_1){
        ans = (n / 2 - cnt_0[0]) + (n / 2 - cnt_1[0]); 
    }else{
        ans = min((n / 2 - cnt_0[0]) + (n / 2 - cnt_1[1]), (n / 2 - cnt_0[1]) + (n / 2 - cnt_1[0]));
    }



    cout << ans << endl;
    

}
//num[i] == num[i + 2] && num[i + 1] == num [i + 3] && num[i] != num[i + 1]