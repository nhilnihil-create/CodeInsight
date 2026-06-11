#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>

using namespace std;

#define dump(x)  cerr << #x << " = " << (x) << endl;
#define PB push_back
#define MP make_pair
#define ll long long

#define FILL(ptr, value) FILL_((ptr), sizeof(ptr)/sizeof(value), (value))
 
template <typename T>
void FILL_(void * ptr, size_t size, T value){
  std::fill((T*)ptr, (T*)ptr+size, value);
}
 

inline int toInt(string s){int v;istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x){ostringstream sout;sout<<x;return sout.str();}

double dp[301][301][301]; // 3, 2, 1

double dfs(int one, int two, int three, int n)
{
  if(dp[three][two][one] != -1)
  {
    return dp[three][two][one];
  }

  double part[3] = {};
  if(one != 0)
  {
    part[0] = dfs(one-1,two,three,n) * one;
  }

  if(two != 0)
  {
    part[1] = dfs(one+1, two-1, three, n) * two;
  }

  if(three != 0)
  {
    part[2] = dfs(one, two+1, three-1, n) * three;
  }

  dp[three][two][one] = (part[0] + part[1] + part[2] + n) / (one + two + three);
  return dp[three][two][one];
}

int main(){
    std::ios::sync_with_stdio(false);

    int n;
    cin >> n;
    int count[3] = {};

    for(int i=0;i<301;++i)
    {
      for(int j=0;j<301;++j)
      {
        for(int k=0;k<301;++k)
        {
          dp[i][j][k] = -1;
        }
      }
    }
    dp[0][0][1] = n;
    for(int i=0;i<n;++i)
    {
      int tmp;
      cin >> tmp;
      tmp--;
      count[tmp]++;
    }

    printf("%.10lf\n", dfs(count[0], count[1], count[2], n));
}