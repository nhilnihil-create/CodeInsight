#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define MOD 1000000007
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
using P = pair<int,int>;

bool IsPrime(int num)
{
    if (num < 2) return false;
    else if (num == 2) return true;
    else if (num % 2 == 0) return false;

    double sqrtNum = sqrt(num);
    for (int i = 3; i <= sqrtNum; i += 2)
    {
        if (num % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
  int Q;
  cin >> Q;
  vector<int> ans;
  vector<int> B(100001);
  int sum=0;
  B[0]=0;
  FOR(i,1,100001){
    if(i%2==1){
      if(IsPrime(i)&&IsPrime((i+1)/2)){
        sum++;
      }
    }
    B[i]=sum;
  }

  REP(i,Q){
    int l,r;
    cin >> l >> r;
    ans.push_back(B[r]-B[l-1]);
  }

  for(auto p:ans){
    cout << p << endl;
  }
}