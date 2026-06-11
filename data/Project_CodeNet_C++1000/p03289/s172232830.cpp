#include<bits/stdc++.h>
using namespace std;
typedef long long  ll ;
typedef double db;
const double pi = 3.141592654;
#define pb         push_back
#define forab(i,a,b)       for(int i=(a);i<=(b);i++)
#define CIN	ios_base::sync_with_stdio(0); cin.tie(0)
#define pcase(z,x)     printf("Case %ld: %lld\n",z,x)
#define nw	 "\n"

int main(void)
{
	CIN;
  string S;
  cin >> S;
  regex R ("A[a-z][a-z]*C[a-z]*[a-z]");
  cout << ((regex_match(S, R)) ? "AC" : "WA") << "\n";
	

}