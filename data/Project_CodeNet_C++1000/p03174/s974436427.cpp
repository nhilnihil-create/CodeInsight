#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include <tuple>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>
using namespace std;

using ll=long long;

typedef long long ll;
typedef pair<int,int> ii;
typedef pair<string,int> si;
typedef pair<int,ii> iii;
typedef vector <si> vsi;
typedef vector <ii> vii;
typedef vector <int> vi;
typedef vector <ll> vll;
typedef vector <vll> vl2d;
typedef vector <vi> vi2d;
typedef vector <char> vc;
typedef vector <bool> vb;
typedef vector <string> vs;
typedef map <string,vs> msvs;
typedef map <string,int> msi;
typedef map <char,int> mci;
typedef map <int,int> mii;
typedef map <long,long> ml;
typedef map <string,string> mss;
#define rep(i,a,n) for (ll i=a;i<n;i++)
#define per(i,a,n) for (ll i=n-1;i>=a;i--)
#define foreach(x,arr) for(auto& x:arr)
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define endl '\n' // Normal `cout << endl` flushes the output every time wich hit performance badly
#define INF 1000000000LL
#define MOD (int)1e9+7
#define deb(x) cout<<#x<<": "<<x<<endl;
#define printArray(arr) for(auto x: arr) { cout<<x<<"\n"; }
#define printMatrix(mat) for(auto x: mat) { cout<<" "; printArray(x); cout<<endl; }
#define printMap(mmap) for(auto p: mmap) { cout<< p.first<<": "<<p.second<<endl; }
#define MIN(a,b) ((a)<(b)?(a):(b))
#define MAX(a,b) ((a)>(b)?(a):(b))
#define forch(ch,str) for(char& c : str)
#define FILL(a,b) memset(a,b,sizeof(a))
//Swift related stuff
#define append push_back
#define nil nullptr
#define guard(_condition) if (bool(_condition)){}
#define count size()
#define let const auto
#define var auto
#define startsWith(str) rfind(str, 0)
#define prq priority_queue
#define tostr(argument) to_string(argument)
#define alphabet "abcdefghijklmnopqrstuvwxyz"

void join(const vector<string>& v, char c, string& s) {

   s.clear();

   for (vector<string>::const_iterator p = v.begin();
        p != v.end(); ++p) {
      s += *p;
      if (p != v.end() - 1)
        s += c;
   }
}

ll dp[21][1<<21];
int n;
ll arr[21][21];
const int mod = 1e9+7;
ll solve(int mi,
         ll mask) {
    guard(dp[mi][mask] == -1) else {
        return dp[mi][mask];
    }

    guard(mi > 0) else {
        rep(i,0,n) {
            int x = 1<<i;
            if(mask & x) {
                if(arr[mi][i]) {
                    dp[mi][mask] = 1;
                    return 1;
                } else {
                    dp[mi][mask] = 0;
                    return 0;
                }
            }
        }
    }



    var res = 0ll;
    rep(i,0,n) {
        if((1<<i & mask) != 0 && arr[mi][i] == 1) {
            res = (res + solve(mi-1, (mask - (1<<i))))%mod;
        }
    }
    dp[mi][mask] = res%mod;
    return dp[mi][mask];
}


int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    memset(dp, -1, sizeof dp);
    vl2d dp(n,vll(1<<n,-1));
    cout <<solve(n-1,(1<<n)-1)  << endl;
    return 0;
}