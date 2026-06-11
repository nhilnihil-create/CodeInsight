#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, m;
  cin >> n >> m;
  vector<int> vn(n+2,0);
  for(int i=0; i<n; ++i) cin >> vn[i+1];
  int ans = 0;
  for(int i=0; i<=m && i<=n; ++i){
    vector<int> minusv(0);
    int nans1 = 0;
    for(int j=0; j<=i; ++j){
      //cout << "取得回数:" << i << " 左から:" << j << endl;
      if(vn[j] >=0) nans1 += vn[j];
      else minusv.push_back(vn[j]);;
      int nans2 = nans1;
      vector<int> minusv2 = minusv;
      for(int k=0; k+j<=i; ++k){
        //cout << "右から:" << k;
        int x = n +1 -k;
        if(vn[x] >=0) nans2 += vn[x];
        else minusv2.push_back(vn[x]);
        sort(minusv2.begin(),minusv2.end());
        reverse(minusv2.begin(),minusv2.end());
        int minx = minusv2.size() -(m -j -k);
        int nans3 = nans2;
        for(int l=0; l<minx; ++l) nans3 += minusv2[l];
        //cout << " スコア:" << nans3 << endl;
        ans = max(ans, nans3);
      }
    }
  }
  cout << ans << endl;
}