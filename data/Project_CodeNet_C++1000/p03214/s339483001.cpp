#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;


int main(void){
  int n,i,a[105],sum=0;
  vector<P> ay;
  
  cin >> n;
  for (i=0;i<n;i++){
    cin >> a[i];
    sum+=a[i];
  }
  
  for (i=0;i<n;i++) ay.push_back(P(abs(sum-a[i]*n),i));
  
  sort(ay.begin(),ay.end());
  
  cout << ay[0].second << endl;
  
  return 0;
}