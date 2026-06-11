#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <climits>
#include <iomanip>
#include <set>
#include <map>
using namespace std;
typedef long long ll;
#define maxll pow(10,18)
int main(){
  vector<ll> dish(5);
  for(int i = 0;i < 5;i++)cin >> dish[i];
  vector<ll> num = {0,1,2,3,4};
  ll res = 0;
  res = maxll;
  do{
    ll before = 0;
    for(int i = 0;i < 5;i++){
      if(before % 10 != 0)before += 10 - before % 10;
      before += dish[num[i]];
    }
    res = min(res,before);
    //cout << endl;
  }while(next_permutation(num.begin(),num.end()));
  cout << res << endl;
}