#include <bits/stdc++.h>
#define INF 2e9
#define MOD 1000000007
#define MOD9 998244353
#define intMAX 51000;
#define PI 3.14159265359
using namespace std;
typedef long long llong;
typedef long double ldouble;

using Graph = vector<vector<int>>;

int main(){
  int N;
  cin >> N;
  int count = 0;
  vector<int> list = {1, 3, 5, 7, 9, 11, 13};
  for(int i=0; i<7-3; ++i){
    for(int j=i+1; j<7-2; ++j){
      for(int k=j+1; k<7-1; ++k){
        for(int l=k+1; l<7; ++l){
          if(list[i]*list[j]*list[k]*list[l] <= N) ++count;
        }
      }
    }
  }
  cout << count << endl;
}