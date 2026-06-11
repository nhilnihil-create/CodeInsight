#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<queue>
#include<cmath>
#include<algorithm>
#include<iomanip>
#include<functional>
#include<set>
#include<map>
#include<climits>
#include<numeric>
#include<utility>
#define ul unsigned long long int
#define ll long long int
#define MAX 1000000+1
using namespace std;
#define F first
#define S second
#define pi 2*acos(0.0)
#define PB push_back
#define CL clear()





int main()
{

  ll n, b = 2;
  vector<ll> v;
  v.clear();
  cin >> n;
  while(n)
  {
      if(n > 0)
      {
          v.PB(n%2);
//          cout << n%2 << endl;
          n =  n/2; n = (-1)*n;


      }
      else
      {
          n = (-1)*n;
          v.PB(n%2);
//          cout << n%2 << endl;
          n = (n + n%2)/2;


      }
  }
//  cout << v.size();
if(v.size()==0)
{
    cout << 0; return 0;
}
reverse(v.begin(), v.end());
  for(ll i = 0; i < v.size(); i++) cout << v[i];

    return 0;
}

