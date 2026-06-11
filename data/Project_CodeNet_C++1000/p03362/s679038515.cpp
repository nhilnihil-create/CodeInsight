#include <iostream> 
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<deque>
#include<iomanip>
#include<sstream>
#include<cmath>
#include<bitset>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define req(i,n) for(int i = 1;i <=  n; i++)
#define rrep(i,n) for(int i = n -1;i >= 0;i--)
#define ALL(obj) begin(obj), end(obj)
#define RALL(obj) rbegin(obj),rend(obj)
typedef long long int ll;
typedef long double ld;
const ll INF = (1LL << 60);
const int INf = 1e9;
template<typename A, size_t N, typename T>
void Fill(A(&array)[N], const T& val) {
    fill((T*)array, (T*)(array + N), val);
}bool isPrime(int x) {
    int i;
    if (x < 2)return 0;
    else if (x == 2) return 1;
    if (x % 2 == 0) return 0;
    for (i = 3; i * i <= x; i += 2) if (x % i == 0) return 0;
    return 1;
}

int main() {   
    int n,k=0; cin >> n; vector<int> b;
    for (int i = 3; i < 55555; i += 5) {
        if (isPrime(i)) {
            b.push_back(i);
        }
    }
    rep(i, n - 1) cout << b[i] << " ";
    cout << b[n - 1] << endl;
}