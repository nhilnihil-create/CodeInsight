#include <bits/stdc++.h>
using namespace std;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

#define rep(i,cc,n) for(int i=cc;i<n;++i)
#define lrep(i,cc,n) for(long long i=cc;i<n;++i)
#define sqrep(i,cc,n) for(long long i=cc;i*i<=n;++i)
#define rrep(i,cc,n) for(long i=cc;i>n;--i)
#define pii pair<int, int>
#define pll pair<long long, long long>
 
using ll = long long;

const vector<int> dx = {1, 0, -1, 0};
const vector<int> dy = {0, 1, 0, -1};
const double PI = 3.1415926535;
const ll inf = 1001001001;
const ll e9  = 1000000000;
const ll mod = 1000000007;

const int MAX = 1000000;
const int MOD = 1000000007;


int main(){
    int n;
    string s;
    cin >> s;
    n = s.size();
    int sum1=0, sum2=0;
    rep(i, 0, n){
        if(i%2==0){
            if(s[i]=='0'){
                sum1++;
            }else{
                sum2++;
            }
        }else{
           if(s[i]=='0'){
                sum2++;
            }else{
                sum1++;
            } 
        }
    }
    cout << min(sum1, sum2) << endl;
}