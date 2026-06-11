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
    map<int, int> even, odd;
    rep(i,n){
        int a;
        cin >> a;
        if(i%2 == 0) even[a]++;
        else odd[a]++;
    }
    int em = 0, om = 0, em2 = 0, om2 = 0, e1 = -1, o1 = -1;
    for(auto p : even){
        if(p.second > em){
            em2 = em;
            em = p.second;
            e1 = p.first;
        }
        else if(p.second > em2){
            em2 = p.second;
        }
    }
    for(auto p : odd){
        if(p.second > om){
            om2 = om;
            om = p.second;
            o1 = p.first;
        }
        else if(p.second > om2){
            om2 = p.second;
        }
    }
    int ans;
    if(e1 != o1){
        ans = n - em - om;
    }
    else{
        ans = min(n-em-om2, n-em2-om);
    }
    cout << ans << endl;
    return 0;
}