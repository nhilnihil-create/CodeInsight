#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
using namespace std;
typedef long long ll;

int main()
{
  int q;
  cin >> q;
  
  for(int i = 0; i < q; i++){
    ll a, b;
    cin >> a >> b;

    if(a > b) swap(a, b);
    
    if(a == b){
      cout << 2*min(a, b) - 2 << endl;  
    }else if(a+1 == b){
      cout << 2*min(a, b) - 2 << endl;
    }else{
      ll c = sqrt(a * b);
      if(c * c == a * b){
        if(a == c){
          cout << 2*c - 2 << endl;
        }else{
          cout << 2*c - 3 << endl;
        }
      }else if(c * (c+1) >= a * b){
        cout << 2*c - 2 << endl;
      }else{
        cout << 2*c - 1 << endl;
      }
    }
  }

  return 0;
}
