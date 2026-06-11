#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;

const ll LINF = 1e18;
const int INF = 1e9;
const ll MOD = 1000000007;

template<class T> inline bool chmin(T& a, T b){
    if(a > b){
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b){
    if(a < b){
        a = b;
        return true;
    }
    return false;
}

int main(){

    int n;
    cin >> n;
    vector<ll> name(5);
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        switch(s[0]){
            case 'M':
                name[0]++;
                break;
            case 'A':
                name[1]++;
                break;
            case 'R':
                name[2]++;
                break;
            case 'C':
                name[3]++;
                break;
            case 'H':
                name[4]++;
                break;
            default:
                break;
        }
    }

    ll ans = 0;
    for(int i = 0; i < 5; i++){
        for(int j = i+1; j < 5; j++){
            for(int k = j+1; k < 5; k++){
                ans += name[i] * name[j] * name[k];
            }
        }
    }
    cout << ans << endl;


    return 0;
}