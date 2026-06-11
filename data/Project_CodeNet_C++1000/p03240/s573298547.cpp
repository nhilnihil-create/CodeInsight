#include<cstdio>
#include<cstdlib>
#include<map>

#define SIZE 100
#define FAIL 0

int N;
long long x[SIZE], y[SIZE], h[SIZE];

long long isAnswer(long long CX, long long CY) {
  long long H = FAIL;
  for(int i=0;i<N;i++)
    {
      if( h[i] == 0LL )
	continue;
      long long ecchi = h[i] + llabs(x[i]-CX) + llabs(y[i]-CY);
      if( ecchi == 0LL )
	continue;
      if( H == FAIL )
	H = ecchi;
      else
	if( H != ecchi )
	  return FAIL;
    }
  return H;
}

int main() {
  ;;"Input <- N";;;scanf("%d",&N);;;;;
  for(int i=0;i<N;i++)
    {
      ;;"Input <- X Y H";;;scanf("%lld %lld %lld",&x[i],&y[i],&h[i]);;;;;
    }
  std::map<long long,int> reg;
  std::map<long long, std::pair<long long, long long>> reg2;
  for(long long CX=0;CX<=100;CX++)
    {
      for(long long CY=0;CY<=100;CY++)
	{
	  long long H;
	  if( ( H = isAnswer(CX,CY) ) != FAIL )
	    {
	      //printf("%lld %lld %lld\n",CX,CY,H);
	      //return 0;
	      reg[H] += 1;
	      reg2[H] = std::pair<long long, long long>(CX,CY);
	    }
	}
    }
  for(auto iter : reg) {
    if( iter.second == 1 ) {
      long long H = iter.first;
      long long X = reg2[H].first;
      long long Y = reg2[H].second;
      printf("%lld %lld %lld\n",X,Y,H);
      return 0;
    }
  }
  return 0;
}
