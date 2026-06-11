#include <iostream> 
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<iomanip>
#include<sstream>
#include<cmath>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define req(i,n) for(int i = 1;i <=  n; i++)
#define rrep(i,n) for(int i = n -1;i >= 0;i--)
typedef long long int ll;
typedef long double ld;
const ll inf = (1 << 30);
template<typename A, size_t N, typename T>
void Fill(A(&array)[N], const T & val) {
    std::fill((T*)array, (T*)(array + N), val);
}
const int MAX = 510000;
const ll MOD = 1000000007;
ll sum = 0;
int main() {
    int n; cin >> n; string s;
    while (n != 0) {
        if (n % 2==0) s = '0'+s;
        else {
            n--; s = '1'+s;
        }
        n /= -2;
    }if (s == "")s = "0";
    cout << s << endl;
}