#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define MOD 1000000007
#define ALL(v) v.begin(), v.end()
#define sz(x) int(x.size())
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
  
  vector<int> sosuu;
  int N;
  cin >> N;
  FOR(i,2,55556){
    if(IsPrime(i)&&i%5==1){
      sosuu.push_back(i);
    }
  }

  REP(i,N){
    cout << sosuu.at(i);
    if(i!=N-1){
      cout << " ";
    }
  }
  cout << endl;
}