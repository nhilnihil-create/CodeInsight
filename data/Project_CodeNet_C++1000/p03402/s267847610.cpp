#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include <fstream>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <functional>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <bitset>
#include <numeric>
#include <unordered_set>
#include <bitset>
#include <limits>
#include <random>
#include <complex>
#include <numeric>
#include <cstdlib>
#include <random>
#include <bits/stdc++.h>


using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
//typedef vector<ll> vec;
//typedef vector<vec> mat;

const ll mod=1000000007ll;
const ll inf=1000000000000000ll;

const ll MAX_N=100010;

ll a,b;

int main(){
  cin>>a>>b;
  ll h=0,ct=10000;
  a--;b--;
  cout<<100<<' '<<100<<endl;
  while(true){
    if(ct>5000){
      if(a>0){
        if(h%2==0){
          if(ct%2==0){
            cout<<'.';
            a--;
          }
          else{
            cout<<'#';
          }
        }
        else{
            cout<<'#';
        }
      }
      else{
        cout<<'#';
      }
    }
    else{
      if(b>0){
        if(h%2==1){
          if(ct%2==0){
            cout<<'#';
            b--;
          }
          else{
            cout<<'.';
          }
        }
        else{
            cout<<'.';
        }
      }
      else{
          cout<<'.';
      }
    }
    ct--;
    if(ct%100==0){
      cout<<endl;
      h++;
    }
    if(ct==0){
      cout<<endl;
      break;
    }
  }
  return 0;
}
