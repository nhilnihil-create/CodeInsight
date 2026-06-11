# include <iostream>
# include <map>
using namespace std;
# define ll long long

int main(){
  int N;
  map<ll, int> freqOfSum;
  
  cin >> N;
  
  ll sum = 0, ans = 0;
  freqOfSum[0]++;
  for(int i=0; i<N; i++){
    int num; cin >> num;
    sum += num;
    ans += freqOfSum[sum];
    freqOfSum[sum]++;
  }
  
  cout << ans << endl;
  return 0;
} 