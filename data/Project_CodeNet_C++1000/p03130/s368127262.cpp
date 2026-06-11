#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#define INF 1e9
#define ALL(v) v.begin(), v.end()
#define max(v) *max_element(v.begin(), v.end())
#define min(v) *min_element(v.begin(), v.end())
using namespace std;
 
int main(void){
  vector<int> a, b;
  int s, t;
  for(int i = 0; i < 3; i++){
    cin>>s>>t;
    a.push_back(s);
    b.push_back(t);
  }
  vector<int> cnt(5);
  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 5; j++){
      if(a[i]==j)
        cnt[j] += 1;
      if(b[i]==j)
        cnt[j] += 1;
    }
  }
  int key=0;
  for(int i = 0; i < 5; i++){
    if(cnt[i]>=3)
      key=1;
  }
  if(key==1)
    cout<<"NO";
  else
    cout<<"YES";
  return 0;
}