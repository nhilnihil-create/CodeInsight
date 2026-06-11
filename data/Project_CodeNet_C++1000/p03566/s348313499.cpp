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
#include <functional>
#include <iomanip>

using namespace std;

#define DEBUG_ //!!提出時にコメントアウト!!
#ifdef DEBUG_
#define dump(x)  cerr << #x << " = " << (x) << endl;
#else
#define dump(x)  ;
#endif

#define equals(a,b) (fabs((a)-(b)) < EPS)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define SZ(x) ((int)(x).size())
#define pb push_back
#define eb emplace_back

//#define int long long

typedef long long LL;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

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

template <typename T>
void print_array(const T &ary, int size){
    REP(i,size){
        cout << ary[i] << " ";
    }
    cout << endl;
}

const int mod = 1e9+7;
const LL LINF = 1001002003004005006ll;
const int INF = 1001001001;
const double EPS = (1e-10);

signed main(int argc, char const *argv[])
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(12);
    int N; 
    cin >> N;
    VI t(N),v(N);
    REP(i,N) cin >> t[i];
    REP(i,N) cin >> v[i];
    VI S(N+1);
    REP(i,N){
        S[i+1] = S[i] + t[i];
    }

    vector<vector<double>> speed(40010);
    REP(i,N){
        int t1 = S[i];
        int t2 = S[i+1];
        for(int j = 2 * t1; j <= 2*t2; j++){
            speed[j].eb(v[i]);
        }
    }
    REP(i,N){
        int t1 = S[i+1];
        double vlimit;
        if(i == N-1) vlimit = 0;
        else vlimit = v[i+1];
        for(int j = 0; j <= 2 * t1; j++){
            speed[j].eb((2.0*t1-j)/ 2.0 + vlimit);
        }
    }
    REP(i,N){
        int t1 = S[i];
        double vlimit;
        if(i == 0) vlimit = 0;
        else vlimit = v[i-1];
        for(int j = 2*t1; j < 40010; j++){
            speed[j].eb((j-2.0*t1) / 2.0 + vlimit);
        }

    }
    double ans = 0;
    REP(i,S[N]*2){
        double v1 = *min_element(speed[i].begin(),speed[i].end());
        double v2 = *min_element(speed[i+1].begin(),speed[i+1].end());

        //cout << "sec: " << i / 2.0 << endl;
        //cout << v1 << endl;

        ans += (v1 + v2) * 0.25;
    }
    cout << ans << endl;

    

}