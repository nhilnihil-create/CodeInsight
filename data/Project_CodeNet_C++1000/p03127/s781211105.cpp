#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<vector>
#include<list>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<stack>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define mp make_pair
#define rep(i, n) for(int i=0;i<n;++i)
#define rrep(i, n) for(int i=n;i>=0;--i)
const int inf=1e9+7;
const ll mod=1e9+7;
const ll big=1e18;
const double PI=2*asin(1);

int main() {
  int N;
  cin>>N;
  vector<int> arr(N);
  for(int i=0;i<N;++i) {
    cin>>arr[i];
  }
  int ans;
  while(arr.size()>1) {
    sort(arr.begin(), arr.end());
    ans = arr[0];
    vector<int> arr1;
    arr1.push_back(ans);
    for(int i=0;i<arr.size();++i) {
      if(arr[i]%ans!=0) arr1.push_back(arr[i]%ans);
    }
    arr.clear();
    for(int i=0;i<arr1.size();++i) {
      arr.push_back(arr1[i]);
    }
  }
  cout<<ans<<endl;
}
