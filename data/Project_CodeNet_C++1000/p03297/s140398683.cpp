#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
//typedef pair<int,int> P;
typedef pair<ll, ll> P;
//typedef pair<int, pair<int, int>> P;
//typedef pair<ll, pair<int, int>> P;
typedef pair<ll,pair<ll,ll>> T;
ll INFL = 1000000000000000010;//10^18 = 2^60
int INF = 2147483600;//10^9
int INFM =100000000;
ll MOD  = 1000000007;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
ll gcd(ll a, ll b){//計算量はO(log(max(a,b))
    if(b == 0) return a;
    return gcd(b, a % b);
}

int main(){
    int T;
    cin >> T;
    for(int i = 0; i < T; i++){
        ll a,b,c,d;
        bool l = 1;
        cin >> a >> b >> c >> d;
        ll g = gcd(b, d);
        if(b - g + (a%g) > c){
            l = 0;
        }
        if(a < b){
            l = 0;
        }
        else if(b > d){
            l = 0;
        }
        else if(c >= b){
            l = 1;
        }
        if(l){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }
}
