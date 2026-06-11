#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const long long MOD=1e9+7;

/*RE→解説後
ソートしないならmap<int,pair<int,int>> なんて使わなくてよい
costの計算は累積和を求めるときでよい
累積和もD飛ばしで和をとるだけでいい
解法を単純にしよう
追記：x,yは1～h*W(90000)のあたいが書かれている座標
*/
int main() {
  int h,w,d;
  cin>>h>>w>>d;
  int x[90009],y[90009];
  rep(i,h) rep(j,w){
    int a;
    cin>>a;
    a--;
    x[a]=i;
    y[a]=j;
  }
  int sums[90009];
  for(int i=d;i<h*w;++i)
    sums[i]=sums[i-d]+abs(x[i]-x[i-d])+abs(y[i]-y[i-d]);
  
  int q;
  cin>>q;
  rep(i,q){
    int l,r;
    cin>>l>>r;
    cout<<sums[r-1]-sums[l-1]<<endl;
  }
}
