#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
typedef long long ll;

int main(){
  int N,K;
  cin >> N >> K;
  int x[N];
  for(int i=0;i<N;i++){
    cin >> x[i];
  }
  vector<int> ans;
  for(int i=0;i<N-K+1;i++){
    if(x[i]<=0&&x[i+K-1]<=0) ans.push_back(abs(x[i]));
    else if(x[i]<0&&x[i+K-1]>0){
      ans.push_back(2*x[i+K-1]+abs(x[i]));
      ans.push_back(x[i+K-1]+2*abs(x[i]));
    }else if(x[i]>=0&&x[i+K-1]>=0) ans.push_back(x[i+K-1]);
  }
  sort(ans.begin(),ans.end());
  cout << ans[0] << endl;
}
