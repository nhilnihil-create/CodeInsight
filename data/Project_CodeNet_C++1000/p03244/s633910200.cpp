#include <bits/stdc++.h>
#define rep(i, n) for(ll i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
const double PI=acos(-1);

template<typename T>
istream& operator>> (istream& is, vector<T> &vec){
    for(T& x: vec) is >> x;
    return is;
}

int main(){
    ll n;
    cin >> n;
    ll odd, even;
    vector<ll> a, b;
    map<ll, ll> oddm, evenm;
    
    rep(i, n){
        if(i%2){
            cin >> odd;
            oddm[odd]++;
            a.push_back(odd);
        }else{
            cin >> even;
            evenm[even]++;
            b.push_back(even);
        }
    }
    //for(auto i : b) cout << i << " "; cout << endl;
    //for(auto i : a) cout << i << " "; cout << endl;
    pair<ll, ll> oddmax, oddmax2, evenmax, evenmax2;
    ll m = 0;
    for(auto i : oddm){
        if(i.second >= m){
            oddmax2 = make_pair(oddmax.first, oddmax.second);
            oddmax = make_pair(i.first, i.second);
            m = i.second;
        }
        if(i.second != oddmax.second && i.second >= oddmax2.second){
            oddmax2 = make_pair(i.first, i.second);
        }
    }
    m = 0;
    for(auto i : evenm){
        if(i.second >= m){
            evenmax2 = make_pair(evenmax.first, evenmax.second);
            evenmax = make_pair(i.first, i.second);
            m = i.second;
        }
        if(i.second != evenmax.second && i.second >= evenmax2.second){
            evenmax2 = make_pair(i.first, i.second);
        }
    }
    ll ans = 0;
    //cout << oddmax.first << " " << oddmax.second << endl;
    //cout << oddmax2.first << " " << oddmax2.second << endl;
    //cout << evenmax.first << " " << evenmax.second << endl;
    //cout << evenmax2.first << " " << evenmax2.second << endl;
    if(oddmax.first == evenmax.first){
        if(oddmax.second > evenmax.second){
            ans += n/2 - oddmax.second;
            ans += n/2 - evenmax2.second;
        }else if(oddmax.second < evenmax.second){
            ans += n/2 - oddmax2.second;
            ans += n/2 - evenmax.second;
        }else{
            if(oddmax2.second > evenmax2.second){
                ans += n/2 - oddmax2.second;
                ans += n/2 - evenmax.second;
            }else{
                ans += n/2 - oddmax.second;
                ans += n/2 - evenmax2.second;
            }
        }
    }else{
        ans = n/2 - oddmax.second;
        ans += n/2 - evenmax.second;
    }

    cout << ans << endl;

    return 0;
}