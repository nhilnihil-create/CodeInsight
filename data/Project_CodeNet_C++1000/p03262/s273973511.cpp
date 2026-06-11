#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define MOD 1000000007
int gcd(int a,int b)
{
	if (a%b==0)
	{
		return(b);
    }
	else
	{
		return(gcd(b,a%b));
    }
}

int main (){
  int N,X;
  cin>>N>>X;
  vector<int>xxx(N);
  rep(i,N){
    int x;
    cin>>x;
    xxx[i]=abs(X-x);
  }
  int ah;
  ah=xxx[0];
  rep(i,N){
    ah=gcd(ah,xxx[i]);
  }
  cout<<ah;
}
