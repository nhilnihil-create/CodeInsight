#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;
using P = pair<int,int>;
using PP = pair<int,pair<int,int>>;
using T = tuple<string,int,int>;
const ll INF = 1LL<<60;
const int ny[4] = {-1,1,0,0}, nx[4] = {0,0,-1,1};
int sy,sx,gy,gx;

int main(){
  int s; cin >> s;
  vector<int> a;
  a.push_back(s);
  while(1){
    int temp = a.back();
    if(temp % 2 == 0){
      a.push_back(temp/2);
    }else{
      a.push_back(temp * 3 + 1);
    }
    for(int i = 0; i < a.size(); i++){
      for(int j = i+1; j < a.size(); j++){
        if(a[i] == a[j]){
          cout << j+1 << endl;
          return 0;
        }
      }
    }
  }
  return 0;
}
