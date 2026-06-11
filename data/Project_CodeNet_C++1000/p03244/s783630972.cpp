#include <bits/stdc++.h>
#include <math.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rrep(i, n) for(int i = 0; i <= (n); i++)
using namespace std;
typedef long long ll;
 
const ll INF = 1LL<<62;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
// 多次元 vector 生成
template<class T>
vector<T> make_vec(size_t a){
    return vector<T>(a);
}
template<class T, class... Ts>
auto make_vec(size_t a, Ts... ts){
  return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}

const int MOD = 1000000007;

int main(){
    int n; cin >> n;
    vector<int> v(n);
    rep(i,n) cin >> v[i];

    map<int, int> even_counter;
    map<int, int> odd_counter;

    for(int i = 0; i < n; i=i+2){
        even_counter[v[i]]++;
    }

    for(int i = 1; i < n; i=i+2){
        odd_counter[v[i]]++;
    }

    int max_even = 0;
    int max_even2 = 0;
    int max_even_num = -1;
    for(auto ec : even_counter){
        if (ec.second >= max_even){
            max_even2 = max_even;
            max_even = ec.second;
            max_even_num = ec.first;
        }
        else{
            if (ec.second >= max_even2){
                max_even2 = ec.second;
            }
        }
    }
    int max_odd = 0;
    int max_odd2 = 0;
    int max_odd_num = -1;
    for(auto oc : odd_counter){
        if (oc.second >= max_odd){
            max_odd2 =  max_odd;
            max_odd = oc.second;
            max_odd_num = oc.first;
        }
        else{
            if(oc.second >= max_odd2){
                max_odd2 = oc.second;
            }
        }
    }

    int ans = 0;
    if (max_even_num != max_odd_num){
        ans = n - max_even - max_odd;
    }
    else{
        ans = min(n-max_even-max_odd2, n-max_odd-max_even2);
    }

    cout << ans << endl;
}

