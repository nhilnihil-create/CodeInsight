#include<iostream>
#include<vector>
#define rep(i,n) for(int i = 0; i < n; i++)
#include<algorithm>

using namespace std;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N; cin >> N;
  vector<int> vec(N);
  rep(i,N){
    cin >> vec[i];
    vec[i] -= i+1;
  }
  sort(vec.begin(),vec.end());
  int index = N/2;
  int b = vec[index];
  long long ans = 0;
  rep(i,N){
    ans += abs(vec[i]-b);
  }

  cout << ans << endl;
}
