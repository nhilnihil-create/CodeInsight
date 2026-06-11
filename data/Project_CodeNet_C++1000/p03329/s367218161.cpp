#include <bits/stdc++.h>
using namespace std;
using  ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)

const int MAX=INT_MAX;

int main(){
  int n;
  std::cin >> n;
  std::vector<int> cnt(n+1,0);
  rep(i,n+1)cnt[i]=i;

  int num[3]={1,6,9};
  for (int i = 2; i >= 1; i--) {

    std::vector<int> exp;
    int nmax=num[i];
    while (nmax<=n) {
      exp.push_back(nmax);
      nmax*=num[i];
    }

    // for (int num : exp) {
    //   std::cout << num << ' ';
    // }
    // std::cout << "" << '\n';


    for (int j = exp.size()-1; j >=0 ; j--) {
      int now=exp[j];
      // std::cout << now << '\n';
      for (int k = now; k <=n ;k+=1) {
        cnt[k]=min(cnt[k],cnt[k-now]+1);
        // std::cout << " " <<k<<" : "<< cnt[k]<<'\n';
      }

    }

    // for (int num : cnt) {
    //   std::cout << num << ' ';
    // }
    // std::cout << "" << '\n';

  }

  std::cout << cnt[n] << '\n';


  return 0;
}
