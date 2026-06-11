#include<bits/stdc++.h>
using namespace std;
int main()
{
  int N,K;
  cin >> N >> K;
  if(N%2==1)N++;
  N=N/2;
  if(N>=K)cout << "YES" << endl;
  if(K>N)cout << "NO" << endl;
}