#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using boost::multiprecision::cpp_int;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ll,pair<ll, ll>> lpll;
typedef pair<ll, int> pli;
typedef pair<int, int> pii;

#define deg_to_rad(deg) (((deg)/360)*2*PI)

const ll LINF = LLONG_MAX;
const ll MOD = 1e9+7;
//const ll MOD = 998244353;

const ld PI = (acos(-1));
const ld EPS = 0.0000000001;
// cout << fixed << setprecision(10) << middle << endl;

int main() {
    // input, ready
    int N,K;
    string S;
    cin >> N >> K >> S;

    //resolve
    int zero_cnt = 0;
    int one_cnt = 0;
    vector<int> zero_list;
    vector<int> one_list;
    for (auto c:S) {
        if (c=='0') {
            zero_cnt++;
            if (one_cnt >0) one_list.push_back(one_cnt);
            one_cnt = 0;
        } else {
            one_cnt++;
            if (zero_cnt >0) zero_list.push_back(zero_cnt);
            zero_cnt = 0;            
        }
    }
    if (zero_cnt >0) zero_list.push_back(zero_cnt);
    if (one_cnt >0) one_list.push_back(one_cnt);

    if (zero_list.size() <= K) {
        cout << N << endl;
        return 0;
    }

    int ans = 0;
    int ret1 = 0;
    int ret = 0;
    int size = min(K,(int)zero_list.size());
    if (S[0] == '0') {
        int r=0;
        int l=0;
        for (int i=0; i<size; i++) {
            ans += zero_list[i];
            if (i<one_list.size()) ans += one_list[i];
            r=i;
        }
        r++;
        ret = ans;
        while (r<zero_list.size()) {
            ans += zero_list[r];
            if (r<one_list.size()) ans += one_list[r];
            if (l > 0) ans -= one_list[l-1];
            ans -= zero_list[l];
            ret = max(ans,ret);
            r++;
            l++;
        }
    } else {
        int r=0;
        int l=0;
        ans += one_list[0];
        for (int i=0; i<size; i++) {
            ans += zero_list[i];
            if ((i+1)<one_list.size()) ans += one_list[i+1];
            r=i;
        }
        r++;
        ret = ans;
        while (r<zero_list.size()) {
            ans += zero_list[r];
            if (r+1<one_list.size()) ans += one_list[r+1];
            ans -= one_list[l];
            ans -= zero_list[l];
            ret = max(ans,ret);
            r++;
            l++;
        }        
    }

    // output
    cout << ret << endl;

    return 0;
}
