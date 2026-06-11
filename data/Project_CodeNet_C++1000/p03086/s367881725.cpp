#include<bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i,n) for(int i=0;i<n;++i)
#define all(v) v.begin(), v.end()
#define PI 3.141592653589793238462643383279
typedef long long int ll;
typedef unsigned long long ull;
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
typedef pair<ll,ll> P;
const long long MOD = 1e9+7;
const ll INF = 1LL << 60;

int main(){
    string s;
    cin >> s;
    int mx = 0;
    int cnt = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] =='A' || s[i] == 'G' || s[i] == 'C' || s[i] == 'T'){
            cnt++;
            mx = max(mx,cnt);
        }
        else cnt = 0;
    }

    cout << mx << endl;


}