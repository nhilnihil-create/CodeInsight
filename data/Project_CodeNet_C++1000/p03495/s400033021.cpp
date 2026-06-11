#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int i, N, K, x, count=0, ans=0;
  
  cin >> N >> K;
  
  vector<int> num(N);
  vector<int> num2(N);

  rep(i,N) {
    cin >> x;
    num[x-1] +=1;
  }
  
  rep(i,N){
    if(num[i]!=0){
      num2[count] =num[i];
      count+=1;
    }
  }
  
  sort(num2.begin(),num2.begin()+count);
  for(i=0;count>K;i++){
    ans+=num2[i];
    count--;
  }
  cout << ans;
}