#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
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
const ll mod1=998244353;
const ll big=1e18;
const double PI=2*asin(1);

int main() {
  int N, K;
  cin>>N>>K;
  string S;
  cin>>S;
  bool zero;
  if(S[0]=='0') zero = true;
  else zero = false;
  vector<int> arr;
  int num = 1;
  for(int i=1;i<S.size();++i) {
    if((zero && S[i]=='0') || (!zero && S[i]=='1')) {
      num++;
    }
    else {
      zero ^= 1;
      arr.push_back(num);
      num = 1;
    }
  }
  if(num>0) arr.push_back(num);
  int ans = 0;
  int tmp = 0;
  int index;
  int arrnum = arr.size();
  if(S[0]=='0') {
    index = 2*K;
    for(int i=0;i<min(index, arrnum);++i) {
      ans += arr[i];
      tmp += arr[i];
    }
    for(int i=index;i<arrnum;i+=2) {
      if(i==index) tmp -= arr[i-index];
      else tmp -= arr[i-index-1]+arr[i-index];
      if(i+1<arrnum) tmp += arr[i]+arr[i+1];
      else tmp += arr[i];
      ans = max(ans, tmp);
    }
  }
  else {
    index = 2*K+1;
    for(int i=0;i<min(index, arrnum);++i) {
      ans += arr[i];
      tmp += arr[i];
    }
    for(int i=index;i<arrnum;i+=2) {
      tmp -= arr[i-index]+arr[i-index+1];
      if(i+1<arrnum) tmp += arr[i]+arr[i+1];
      else tmp += arr[i];
      ans = max(ans, tmp);
    }
  }
  cout<<ans<<endl;
}

