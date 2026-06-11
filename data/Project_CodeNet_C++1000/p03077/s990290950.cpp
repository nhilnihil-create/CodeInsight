#include<bits/stdc++.h>
#define rep(i,f,n) for(int i=(f); (i) < (n); i++)
#define repe(i,f,n) for(int i=(f); (i) <= (n); i++)
using namespace std;

typedef long long ll;
ll INF = 1LL << 60;
ll MAX = 100010;


int
main() 
{
  ll n;
  cin >> n;
  ll min = INF;
  rep(i, 0, 5){
    ll tmp; cin >> tmp;  
    if(min > tmp) min = tmp;
  }

  if(n <= min){
    cout << 5 << endl;
  } else if(n % min == 0){
    cout << 4 + (n / min) << endl;
  } else {
    cout << 5 + (n / min) << endl;
  }

}

