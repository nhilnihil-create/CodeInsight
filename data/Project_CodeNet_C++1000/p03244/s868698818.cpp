#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    map<int, int> odd, even;
    rep(i,n){
        int a;
        cin >> a;
        if(i%2 == 0) even[a]++;
        else odd[a]++;
    }
    int modd = 0, meven = 0, m2odd = 0, m2even = 0, odd_num = -1, even_num = -1;
    for(auto p : odd){
        if(p.second > modd){
            m2odd = modd;
            modd = p.second;
            odd_num = p.first;
        }
        else if(p.second > m2odd){
            m2odd = p.second;
        }
    }
    for(auto p : even){
        if(p.second > meven){
            m2even = meven;
            meven = p.second;
            even_num = p.first;
        }
        else if(p.second > m2even){
            m2even = p.second;
        }
    }
    int ans;
    if(odd_num != even_num){
        ans = n - modd - meven;
    }
    else{
        ans = n - m2odd - meven;
        chmin(ans, n - modd - m2even);
    }
    cout << ans << endl;
    return 0;
}