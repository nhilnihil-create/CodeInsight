#include <bits/stdc++.h>
using namespace std;
#define REP(i,N) for(i=0;i<N;i++)
#define MAX_I INT_MAX //1e9
#define MIN_I INT_MIN //-1e9
#define MAX_UI UINT_MAX //1e9
#define MAX_LL LLONG_MAX //1e18
#define MIN_LL LLONG_MIN //-1e18
#define MAX_ULL ULLONG_MAX //1e19
  typedef long long ll;
  typedef pair<int,int> PII;
  typedef pair<char,char> PCC;
  typedef pair<ll,ll> PLL;
  typedef pair<char,int> PCI;
  typedef pair<int,char> PIC;
  typedef pair<ll,int> PLI;
  typedef pair<int,ll> PIL;
  typedef pair<ll,char> PLC;
  typedef pair<char,ll> PCL;

double snuke_num(ll n){
  ll N = n;
  ll digit_sum = 0;
  while(n!=0){
    digit_sum += n%10;
    n/=10;
  }
  return (double)N/digit_sum;
}

vector<ll> make_snuke(){
  int i;
  vector<ll> snuke;
  REP(i,9) snuke.push_back(i+1);
  REP(i,9) snuke.push_back((i+1)*10+9);
  ll s = 100;
  REP(i,13){
    for(ll j=2;j<=200;j++){
      snuke.push_back(j*s-1);
    }
    s *= 10;
  }
  sort(snuke.begin(),snuke.end());
  double min = 1e+16;
  ll pre = 0;
  vector<ll> ans;
  for(i=snuke.size()-1;i>=0;i--){
    if(pre==snuke[i])continue;
    double snukeNum = snuke_num(snuke[i]);
    if(snuke_num(snuke[i]) <= min){
      ans.push_back(snuke[i]);
      min = snukeNum;
    }
    pre = snuke[i];
  }
  sort(ans.begin(),ans.end());
  return ans;
}

int main(void){
  ll K;cin >> K;
  vector<ll> ans = make_snuke();
  int i;REP(i,K) cout << ans[i] << endl;
  return 0;
}
