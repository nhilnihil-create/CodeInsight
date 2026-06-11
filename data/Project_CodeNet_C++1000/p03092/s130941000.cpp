#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(),(x).end()
#define SP <<" "<<
#define MOD 1000000007
#define IINF 1000000000
#define LINF 1000000000000000000

typedef long long LL;
typedef long double LD;

struct BIT{
private:
  vector<int> array;
  int n;
public:
  BIT(int _n):array(_n+1,0),n(_n){}

  int sum(int i){
    int s=0;
    i++;
    while(i>0){
      s+=array[i];
      i-=i&-i;
    }
    return s;
  }

  int add(int i){
    i++;
    while(i<=n){
      array[i]++;
      i+=i&-i;
    }
  }
};

int main(){
  LL n,a,b;
  cin >> n >> a >> b;
  vector<int> p(n);
  vector<int> pos(n);
  for(int i=0;i<n;i++){
    cin >> p[i];
    p[i]--;
    pos[p[i]]=i;
  }
  vector<vector<LL>> dp(n,vector<LL>(n,0));
  BIT bit(n);
  bit.add(pos[0]);
  for(int i=1;i<n;i++){
    for(int j=0;j<n;j++){
      if(pos[i]>j) dp[i][j]=dp[i-1][j];
      else{
        dp[i][j]=min((bit.sum(j)-bit.sum(pos[i])==0?0:a)+dp[i-1][j],b*(bit.sum(j)-bit.sum(pos[i]))+(pos[i]>0?dp[i-1][pos[i]-1]:0));
      }
      // cout << dp[i][j] << " ";
    }
    bit.add(pos[i]);
    // cout << endl;
  }
  cout << dp[n-1][n-1] << endl;
  return 0;
}
