#include <bits/stdc++.h>
#define For(i, a, b) for(int (i)=(a); (i)<(b); ++(i))
#define rFor(i, a, b) for(int (i)=(a)-1; (i)>=(b); --(i))
#define rep(i, n) For((i), 0, (n))
#define rrep(i, n) rFor((i), (n), 0)
#define fi first
#define se second
using namespace std;
typedef long long lint;
typedef unsigned long long ulint;
typedef pair<int, int> pii;
template<class T>bool chmax(T &a, const T &b){if(a<b){a=b; return true;} return false;}
template<class T>bool chmin(T &a, const T &b){if(a>b){a=b; return true;} return false;}

constexpr lint mod = 1e9+7;
constexpr lint INF = mod;
constexpr int MAX = 200010;

int n, q;
string s;
char t[MAX], d[MAX];

int check(int mid){
        rep(i, q){
                if(s[mid]==t[i]) d[i]=='L' ? --mid : ++mid;
                if(mid<0) return 1;
                else if(mid==n) return 2;
        }
        return 0;
}

int main(){
        scanf("%d%d", &n, &q);
        cin>>s;
        rep(i, q) scanf(" %c %c", &t[i], &d[i]);
        int ans=n;
        int low=0, high=n;
        if(check(low)==1){
                while(high-low>1){
                        int mid=(high+low)/2;
                        (check(mid)==1 ? low : high)=mid;
                }
                ans-=low+1;
        }
        low=-1, high=n-1;
        if(check(high)==2){
                while(high-low>1){
                        int mid=(high+low)/2;
                        (check(mid)==2 ? high : low)=mid;
                }
                ans-=n-high;
        }
        printf("%d\n", ans);
}