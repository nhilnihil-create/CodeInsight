#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
typedef pair<ll,int> P;
typedef tuple<ll,ll,ll> T;
const long long INF = 1LL<<60;
const int MOD = 1000000000+7;
#define rev(s) (string((s).rbegin(), (s).rend()))
template < typename T > inline string toString( const T &a ) { ostringstream oss; oss << a; return oss.str(); };
// cout << fixed << setprecision(10) << ans << endl; 有効桁数指定
// *min_element(c + l, c + r) *max_element(c + l, c + r) 配列の中のmin-max
// int dx[8]={1,1,0,-1,-1,-1,0,1};
// int dy[8]={0,1,1,1,0,-1,-1,-1};
// int dx[4]={1,0,-1,0};
// int dy[4]={0,1,0,-1};
// ~ は、-1の時だけfalse

// int n;

// int dfs(int now,int nxt,int bit) {
//     int nn = now*10 + nxt;
//     if(nn > n) {
//         if(bit != 7) return 0;
//         else {
//             if(nxt==3) return 1;
//             else if(nxt==5) {
//                 if(nn-2 > n) {
//                     return 0;
//                 } else {
//                     return 1;
//                 }
//             } else {
//                 if(nn-2>n) {
//                     return 0;
//                 } else {
//                     return 1;
//                 }
//             }
//         }
//     }
//     int mask = ((nxt-1)/2)-1;
//     bit |= (1<<mask);
//     // cout << nn << " " << bit <<endl;
//     // if (bit == 7) {
//     //     return dfs(nn,3,sum+1,bit) + dfs(nn,5,sum+1,bit) + dfs(nn,7,sum+1,bit);
//     // } else{
//     //     return dfs(nn,3,sum,bit) + dfs(nn,5,sum,bit) + dfs(nn,7,sum,bit);
//     // }
//     return dfs(nn,3,bit) + dfs(nn,5,bit) + dfs(nn,7,bit);
//     // int p=0;
//     // if(nn * 10 + 3 > n) {
//     //     if(bit == 7) return p+1;
//     //     else return 0;
//     // } else {
//     //     p+=dfs(nn,3,bit);
//     // }
//     // if(nn * 10 + 5 > n) {
//     //     if(bit == 7) return p+1;
//     //     else return 0;
//     // } else {
//     //     p+=dfs(nn,5,bit);
//     // }
//     // if(nn * 10 + 7 > n) {
//     //     if(bit == 7) return p+1;
//     //     else return 0;
//     // } else {
//     //     p+=dfs(nn,7,bit);
//     // }
//     // return p;
// }

// int main () {
//     cin>>n;
//     int ans = dfs(0,3,0) + dfs(0,5,0) + dfs(0,7,0);
//     cout<<ans<<endl;
// }

int main () {
    ll n;cin>>n;
    int ans=0;
    queue<P> que;
    que.push(P(3,1));
    que.push(P(5,2));
    que.push(P(7,4));

    while(1) {
        P p = que.front();que.pop();
        ll now = p.first;int bit = p.second;
        if(now > n) break;
        if(bit == 7) ans++;
        que.push(P(now*10+3,bit|1));
        que.push(P(now*10+5,bit|2));
        que.push(P(now*10+7,bit|4));
    }
    cout<<ans<<endl;
}