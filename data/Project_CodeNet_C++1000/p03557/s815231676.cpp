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
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    vector<int> c(n);

    rep(i,n)cin >> a[i];
    rep(i,n)cin >> b[i];
    rep(i,n)cin >> c[i];

    sort(all(a));
    sort(all(b));
    sort(all(c));

    ll cnt = 0;

    for(int i = 0; i < n; i++){ //bの要素を順繰りに見ていく
        int right = n;
        int left = -1;
        while(right - left > 1){
            int mid = (right + left)/2;
            if(a[mid] >= b[i]){
                right = mid;
            }else{
                left = mid;
            }
        }
        int num1 = left + 1;
        //cout << "num1:" << num1 << endl;
        right = n;
        left = -1;
        while(right - left > 1){
            int mid = (right + left)/2;
            if(c[mid] > b[i]){
                right = mid;
            }else{
                left = mid;
            }
        }
        int num2 = n - right;
        //cout << "num2:" << num2 << endl;
        cnt += (ll)num1 * num2;
    }

    cout << cnt << endl;


}