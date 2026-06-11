#include <bits/stdc++.h>
 
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,n) for(int i=1;i<=(n);i++)
#define lol long long
#define SUM(n) ((n)+1)*(n)/2　//1〜nまでの総和を求める式
#define mp make_pair
#define fi first
#define se second
#define pu push_back
#define SYOU(x) setprecision(x+1) //小数点桁数を指定する
#define abs(x,y) (max(x,y)-min(x,y))
#define all(v) v.begin(),v.end()
#define UPDight(a,b) (a+b-1)/b //小数点切り上げ 
const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3fLL;
const int MOD=int(1e9)+7; 
using namespace std;
using pii = pair<int,int>;
typedef vector<int> vit;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vit a(n + 5), sum(n + 5, 0);
    reps(i, n){
      cin >> a[i];
    }
    a[0] = 0;
    a[n + 1] = 0;
    reps(i, n + 1){
      sum[i] += sum[i - 1] + abs(a[i], a[i - 1]);
    }
    reps(i, n){
      cout << (sum[n + 1] - sum[i + 1]) + sum[i - 1] + abs(a[i - 1], a[i + 1]) << '\n';
    }
    return 0;
}
