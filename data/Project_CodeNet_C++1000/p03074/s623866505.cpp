#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0;i<n;i++)
#define erep(i,n) for(int i = 0;i<=n;i++)
#define rep1(i,n) for(int i = 1;i<n;i++)
#define erep1(i,n) for(int i = 1;i<=n;i++)
typedef long long ll;
#define vint vector<int>
#define vvint vector<vector<int>>
#define vstring vector<string>
#define vdouble vector<double>
#define vll vector<ll>:
#define vbool vector<bool>
#define INF 1101010101010101010
#define MOD 1000000007
#define int long long
using P = pair<int,int>;

signed main(){
  int n,k;
  cin >> n >> k;
  string s;
  cin >> s;
  vector<int> num;
  if(s[0] == '0') num.push_back(0);
  for(int i = 0;i < s.size();){
    int j = i;
    while(j < s.size() && s[j] == s[i]) j++;
    num.push_back(j-i);
    i = j;
  }
  vector<int> sums(num.size()+1,0);
  rep(i,num.size()) sums[i+1] = sums[i] + num[i];
  int ans = 0;
  for(int left = 0;left < sums.size();left+=2){
    int right = left + 2*k + 1;
    if(right > sums.size()-1) right = sums.size()-1; 
    ans = max(ans,sums[right] - sums[left]);
  }
  cout << ans << endl;
}