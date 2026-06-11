#include<iostream>
#include<vector>

struct segment_tree_max{
  int n;
  std::vector<int64_t> data;
  int64_t identity;

  int64_t max(int64_t a,int64_t b){return a<b?b:a;}

  segment_tree_max(){}
  segment_tree_max(int sz,int64_t id){
    n = 1;
    while(n<sz)n*=2;
    identity = id;
    data.resize(2*n,identity);
  }
  void set(int i,int64_t val){
    i += n;
    data[i] = val;
    i /= 2;
    while(i){
      data[i] = max(data[2*i],data[2*i+1]);
      i /= 2;
    }
  }
  int64_t get_max(int l,int r){
    l += n, r += n;
    int64_t res = identity;
    while(l<r){
      if(l&1) res = max(res,data[l++]);
      if(r&1) res = max(res,data[--r]);
      l /= 2, r /= 2;
    }
    return res;
  }
  int64_t operator[](int k)const{
    return data[k+n];
  }
};

int main(){

  int n;
  std::cin>>n;
  std::vector<int64_t> h(n),a(n);
  for(auto& hi:h)std::cin>>hi;
  for(auto& ai:a)std::cin>>ai;

/*
  dp[i][j] :=  i 番目まで見て、高さが j のときの美しさの最大値
  初期値は全部 0, 更新は
  for i = 1..n:
    dp[i] = dp[i-1]
    dp[i][hi] = max(dp[i-1][0..hi]) + ai
  i 番目で更新されるのは dp[i][hi] だけなので時系列の i は不必要とわかる
  dp[k] := 高さ k の時の美しさの最大値
  for i = 1..n:
    dp[hi] = max(dp[0..hi]) + ai
  max(dp[0..hi]) を愚直に求めると全体で O(NH) かかる(H = h_i_max)
  h_i_max <= N なので O(N^2)
  ここで segment tree を使うと max(dp[0..hi]) を高速に求められ、
  O(NlogH) = O(NlogN) で解くことが出来る
*/

  segment_tree_max dp(n+1,0);

  for(int i=0;i<n;++i){
    auto& hi = h[i];
    auto& ai = a[i];
    int64_t tmp = dp.get_max(0,hi);
    dp.set(hi,tmp+ai);
  }

  int64_t ans = dp.get_max(0,n+1);
  std::cout<<ans<<std::endl;

}