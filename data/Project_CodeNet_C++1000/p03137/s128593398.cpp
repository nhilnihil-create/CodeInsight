#include <bits/stdc++.h>
using namespace std;
 
#define froop1(a,n) for(int i = a;i < n;i++)
#define froop2(a,n) for(int i = a;i > n;i--)
int main(){
	long long N,M,sum = 0;
  cin >> N >> M;
  vector<long long> dist(M);
  vector<long long> x(M);
  froop1(0,M){
    cin >> x.at(i);
  }
  if(N >= x.size()){
    cout << 0 << endl;
    return 0;
  }
  
  sort(x.begin(),x.end());
  sum = x.at(x.size() - 1) - x.at(0);
  froop1(1,M){
    dist.at(i - 1) = x.at(i) - x.at(i - 1);
  }
  sort(dist.begin(),dist.end(),greater<int>());
  froop1(0,N - 1){
    sum -= dist.at(i);
  }
  cout << sum << endl;
}
  