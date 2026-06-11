#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

//template
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define rrep(i,a,b) for(int i=(a);i>(b);i--)
#define ALL(v) (v).begin(),(v).end()
typedef long long int ll; typedef pair<ll, ll> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<typename A,size_t N,typename T>void Fill(A(&array)[N],const T &val){fill((T*)array, (T*)(array+N), val);}
const int inf = 0x3fffffff; const ll INF = 0x3fffffffffffffff;
//template end

bitset<4000010> dp;

int main(){
    int n; scanf("%d",&n);
    vector<int> a(n);
    rep(i,0,n)scanf("%d",&a[i]);
    int sum=0; rep(i,0,n)sum+=a[i];
    dp[0]=1;
    rep(i,0,n)dp|=(dp<<a[i]);
    rep(i,(sum+1)/2,4000010)if(dp[i]){
        printf("%d\n",i); break;
    }
    return 0;
}