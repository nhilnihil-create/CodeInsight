#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstdlib>

using namespace std;

typedef long long ll;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }


int N;
ll K, A[101010];
ll dp[50][2];


int main()
{
  cin >> N >> K;

  for(long long i=0; i<N; i++)
    cin >> A[i];

  for(int i=0; i<50; i++)
      dp[i][0] = dp[i][1] = -1;
    


  long long Amax=0;
  for(int i=0; i<N; i++)
    chmax(Amax, A[i]);

  dp[0][0]=0;
  for(int digit=0; digit<44; digit++)
    {
      long long mask = 1LL << 43-digit;
      int num = 0;

      for(int i=0; i<N; i++)
	{
	  if(mask & A[i])//下からdigit目の桁が1ならnum++
	    num++;
	}

      //XORだから，1のほうが多いときはXのdigitは0
      long long diff0 = mask * num;   //diff0の0はnumが1である．Xのdigitは0
      long long diff1 = mask * (N-num);   //

      //dp[digit][smaller]


	  //smaller->smaller : smallerが存在する場合に限る
	  if(dp[digit][1]>=0)
	    {
	      dp[digit+1][1] = max(dp[digit][1] + diff1, dp[digit][1] + diff0);
	    }

	  //if(dp[digit][0]>=0) //なぜ，これで
	  //{
	      if(K&mask)  //1が立ってる
		{
		  //limit->smaller
		  chmax(dp[digit+1][1], dp[digit][0]+diff0);
		  
		  //limit->limit
		  chmax(dp[digit+1][0], dp[digit][0]+diff1);
		}
	      else
		{
		  //limit->limit
		  chmax(dp[digit+1][0], dp[digit][0]+diff0);
		}
	      //}
    }

  cout << max(dp[44][0], dp[44][1]) << endl;
  


  return 0;
}
