#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;
#define vi vector<int>
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define SZ(x) (int)(x.size())
#define rep(i,a,b) for(int i=a;i<b;i++)
#define per(i,a,b) for(int i=b-1;i>=a;i--)
#define inf 1000000007
#define mod 1000000007
#define ull unsigned long long
#define ll long long
template <class T,class U>inline void Max(T &a,U b){if(a<b)a=b;}
template <class T,class U>inline void Min(T &a,U b){if(a>b)a=b;}


int dp[1<<26];
const int INF = 1e9;
 
int main() {
    string S;
    cin >> S;
    rep(i,0,(1<<26)) dp[i] = INF;
    dp[0] = 0;
    int stat = 0;
    rep(i,0,SZ(S)){
        stat ^= 1 << (S[i]-'a');
        rep(j,0,26) {
            int tmp = (stat^(1<<j));
            dp[stat] = min(dp[stat], dp[tmp]+1);
        }
    }
    cout<<max(dp[stat],1)<< endl;
    return 0;
}
