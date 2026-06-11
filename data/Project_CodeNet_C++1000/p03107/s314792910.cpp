#include <bits/stdc++.h>
#define rep(i, n) for(long long int i = 0; i < n; i++)
#define _rep(i, m, n) for(long long int i = m; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
//const int N = 1000000;
const ll mod = 1000000007;
//using Graph = vector<vector<int>>;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int dh[8] = {0, 0, 1, 1, 1, -1, -1, -1};
const int dw[8] = {1, -1, 0, 1, -1, 0, 1, -1};
  
ll gcd(ll A, ll B){
    if(B == 0)return A;
    return gcd(B, A % B);
}
ll lcm(ll A, ll B){
    return A * (B / gcd(A, B));
}
using Edge = pair<int,int>;
using Graph = vector<vector<Edge>>;
Graph G;
  
/*------------------------------------------------------------------*/

int main(){
    string s; cin >> s;
    int n = s.size();
    int r = 0;
    rep(i, n){
        if(s[i] == '0') r++;
    }
    cout << n - abs(n - 2 * r) << endl;    
}