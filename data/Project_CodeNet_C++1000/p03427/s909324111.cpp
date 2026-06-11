#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef vector<vector<int> > Graph;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int keta(ll x){
    int ans = 0;
    while(x>0){
        x/=10;
        ans++;
    }
    return ans;
}
int saidai(ll x){
    while(x>=10){
        x/=10;
    }
    return x;
}
bool nine(ll x){
    while(x>=10){
        int y=x%10;
        if(y!=9)return false;
        x/=10;
    }
    return true;
}
int main(){
    ll n;
    cin >> n;
    if(nine(n)) cout << (keta(n)-1)*9+saidai(n) << endl;
    else cout << (keta(n)-1)*9+saidai(n)-1 << endl;
    return 0;
}