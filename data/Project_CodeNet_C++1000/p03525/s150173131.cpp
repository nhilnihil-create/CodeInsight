#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <numeric>
#include <list>
#include <map>

using namespace std;    
typedef long long ll;
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()

ll minDiff(vector<ll> v, ll val){
    ll ans = 24;
    for(int i = 0; i < v.size(); i++){
        ans = min(ans, abs(v[i] - val));
    }
    return ans;
}

int main(){

    ll N;
    cin >> N;

    vector<ll> v(N);
    for(int i = 0; i < N; i++) cin >> v[i];

    sort(all(v));
    vector<ll> left;
    vector<ll> right;

    if(N == 1){
        cout << v[0] << endl;
        return 0;
    }

    for(int i = 0; i < N; i++){
        if(left.size() == 0) left.push_back(v[i]);
        else if(right.size() == 0) right.push_back(v[i]);
        else{
            ll l = minDiff(left, v[i]);
            ll r = minDiff(right, v[i]);
            if(l < r) right.push_back(v[i]);
            else left.push_back(v[i]);
        }
    } 

    sort(all(left));
    sort(all(right));
    ll lmin = left[0];
    ll rmin = right[0];
    for(int i = 0; i < left.size() - 1; i++){
        lmin = min(lmin, left[i+1] - left[i]);
    }; 
    for(int i = 0; i < right.size() - 1; i++){
        rmin = min(rmin, right[i+1] - right[i]);
    }; 

    cout << min( {
        lmin,
        rmin,
        min( right.back() + left.back() , 24 - abs( right.back() + left.back() )   )
    } )
    << endl;

}