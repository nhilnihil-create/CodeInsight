// 3_codefestival2017final_c
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>// C++
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i++)
#define SZ(x) ((int)(x).size())
#define INF (1e16)
#define MOD (1000000007)
typedef long long ll;

int func(int bit){
    int now = 0;
    int ans = 12;
    for(int i = 1; i <= 23; i++){
        if(bit & (1 << i)){
            ans = min(ans, i - now);
            now = i;
        }
    }
    ans = min(ans, 24 - now);
    return ans;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> v(13);
    rep(i, 13){
        v[i] = 0;
    }
    v[0] = 1;
    rep(i, n){
        int d;
        cin >> d;
        v[d]++;
    }

    int ans = 0;

    rep(i, (1 << 24)){
        if((i & 1) == 0) continue;

        int a, b;
        int flag = 0;
        for(int j = 1; j <= 11; j++){
            if(i & (1 << j)) a = 1;
            else a = 0;

            if(i & (1 << (24 - j))) b = 1;
            else b = 0;

            if(a + b > v[j] || (a + b == 0 && v[j] > 0)){
                flag = 1;
                break;
            }
            if(a + b < v[j]){
                ans = max(ans, 0);
                flag = 1;
                break;
            }
        }
        if((i & (1 << 12)) && v[12] == 0){
            flag = 1;
        }
        if((i & (1 << 12)) == 0 && v[12] > 0){
            flag = 1;
        }

        if(v[0] > 1){
            flag = 1;
            ans = max(ans, 0);
        }
        if(v[12] > 1){
            flag = 1;
            ans = max(ans, 0);
        }

        if(flag) continue;

        ans = max(ans, func(i));
    }

    cout << ans << endl;
    return 0;
}
