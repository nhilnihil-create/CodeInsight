#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int p_MAX = 55555;
vector<int> prime;
int calc_prime()
{
  bool notPrime[p_MAX];
  int n = sqrt(p_MAX)+1;
  notPrime[0]=1;
  notPrime[1]=1;
  for(int i=0;i<=n;i++){
    if(notPrime[i])
      continue;
    int m = p_MAX/i;
    for(int j=2;j<=m;j++)
      notPrime[j*i]=1;
  }
  prime.clear();
  for(int i=0;i<p_MAX;i++)
    if(!notPrime[i])
      prime.push_back(i);
  return 0;
}
int main()
{
  int n,i;
  cin >> n;
  calc_prime();
  for(i=0;i<prime.size()&&n>0;i++)
    if(prime[i]%5==1){
      cout << prime[i] << " ";
      n--;
    }
  return 0;
}