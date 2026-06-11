#include <iostream>
#include <string>
#include <vector>
#include <algorithm> 
#include <utility> 
#include <tuple> 
#include <cstdint> 
#include <cstdio> 
#include <map> 
#include <queue> 
#include <set> 
#include <stack> 
#include <deque> 
#include <unordered_map> 
#include <unordered_set> 
#include <bitset> 
#include <cctype> 
#include <cmath>
#include <iomanip>
#include <ctype.h>

using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi >;
using vl = vector<ll>;
using vvl = vector<vl >;
using pairi = pair<int, int>;
using pairl = pair<ll, ll>;

#define TR ","
#define TS " "
#define rep(i,N) for(int i=0;i<(int)N;++i)
#define rpt(i,a,b) for(int i=a;i<(int)b;++i)
#define all(v) v.begin(), v.end()
#define IO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

ll gcd(ll a, ll b) {
    if (a < b) swap(a, b);
    if (b == 0) return a;
    return gcd(b, a % b);
}

ll lcm(ll x, ll y) {
    return x / gcd(x, y) * y;
}

void printVector(const vector<ll>& vec) {
    for (ll value : vec) {
        cout << value << " ";
    }
    cout << endl;
}

vector<int> IntegerToVector(int bit, int N) {
    vector<int> S;
    for (int i = 0; i < N; ++i) {
        if (bit & (1 << i)) {
            S.push_back(i);
        }
    }
    return S;
}

int main()
{
    IO;

    string str; cin>>str;
    ll K; cin>>K;
    set<string> bubun;

    int a=str.size();
    int b=min(5,a);
  
    rep(i,a){
       rpt(j,1,min(b+1,a-i+1)){
         bubun.insert(str.substr(i,j));
       }
    }

    auto itr=bubun.begin();
    rep(i,K-1) itr++;
    cout<<*itr<<endl;

}
