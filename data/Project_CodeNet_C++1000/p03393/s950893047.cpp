#include <iostream>
#include <algorithm>
#include <utility>
#include <string>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <map>
#include <math.h>
#include <string.h>
#include <iomanip>
#include <numeric>
#include <cstdlib>
#include <cstdint>
#include <cmath>

using namespace std;

using ll = long long;
using pll = pair<ll, ll>;
using vl = vector<ll>;
using vll = vector<vl>;
using vpll = vector<pll>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = ((int)(n)-1); i >= 0; i--)
#define Rep(i, n) for (long long i = 0; i< (long long)(n); i++)
#define RRep(i,n) for (long long i = ((long long)(n)-1); i>=0; i--)

struct Edge{
    int to;
    int weight;
    Edge(int t, int w) : to(t), weight(w){ }
};

using Graph = vector<vector<Edge>>;
using graph = vector<vector<int>>;

template <class T>
inline bool chmin(T &a, T b){
    if (a > b){
        a = b;
        return true;
    }
    return false;
}

template <class T>
inline bool chmax(T &a, T b){
    if (a < b){
        a = b;
        return true;
    }
    return false;
}

template <class T>
T gcd(T a, T b){
    if( b==0 ) return a;
    else return gcd(b, a%b);
}

template <class T>
T lcm(T a, T b){
    return (a*b)/gcd(a,b);
}

int INF = 1e9+7;

vector<int> dx = {-1,0,1,0};
vector<int> dy = {0,-1,0,1};

int main(){
    string s;
    cin >> s;
    vector<int> a(26,0);
    rep(i,s.size()){
        a[s[i]-'a']++;
    }
    if(s.size()<26){
        rep(i,26){
            if(a[i]) continue;
            else{
                cout << s << char('a'+i) << endl;
                return 0;
            }
        }
    }
    else{
        rrep(i,s.size()-1){
            if(s[i+1]<s[i]){
                continue;
            }
            else{
                int ans = INF;
                for(int j = i+1; j<s.size(); j++){
                    if(s[i]<s[j]){
                        chmin(ans,s[j]-0);
                    }
                }
                rep(j,i){
                    cout << s[j];
                }
                cout << char(ans) << endl;
                return 0;
            }
        }
        cout << -1 << endl;
    }
    return 0;
}