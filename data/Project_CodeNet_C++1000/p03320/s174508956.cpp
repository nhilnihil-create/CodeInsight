#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <cmath>
#include <tuple>
#include <cstdio>
#include <bitset>
#include <sstream>
#include <iterator>
#include <numeric>
#include <map>
#include <cstring>
#include <set>

using namespace std;

#define DEBUG_ //!!提出時にコメントアウト!!
#ifdef DEBUG_
	#define dump(x)  cerr << #x << " = " << (x) << endl;
#else
	#define dump(x)  ; //何もしない文
#endif

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define SZ(x) ((int)(x).size()) //unsignedのサイズをint型に変換
#define pb push_back
#define eb emplace_back

//#define int long long

typedef long long LL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

template <typename T>
std::string printVector(const std::vector<T> &data)
{
    std::stringstream ss;
    std::ostream_iterator<T> out_it(ss, ", ");
    ss << "[";
    std::copy(data.begin(), data.end() - 1, out_it);
    ss << data.back() << "]";
    return ss.str();
}

const int MOD = 1e9+7;
const LL LINF = 1001002003004005006ll;
const int INF = 1001001001;

LL dsum(LL n)
{
    LL res = 0;
    while(n!=0)
    {
        res += n%10;
        n /= 10;
    }
    return res;
}

LL snuke(LL n)
{
    priority_queue<pair<double,LL>, vector<pair<double,LL>>, greater<pair<double,LL>>> val;

    LL dig = 0; // 9が連続する下の桁

    while(LL(pow(10,dig)) <= n*100)
    {
        FOR(i,1,11)
        {
            LL v = max(n - n % LL(pow(10,dig+1)),0LL) + i * LL(pow(10,dig)) - 1;

            if(v >= n) val.push(make_pair(double(v)/dsum(v), v));
        }

        dig++;
    }

    LL ans = val.top().second;
    return ans;

}


signed main(int argc, char const *argv[])
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    LL K; cin>>K;
    LL pre = 1;
    REP(i,K)
    {
        cout << pre << endl;
        pre = snuke(pre+1);
    }



}