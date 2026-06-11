#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int N;
  cin >> N;
  map<int,int> m;
  int max=0;
  for(int i=0;i<N;i++){
    int tmp;
    cin >> tmp;
    m[tmp]++;
    if(max < tmp){
      max = tmp;
    }
  }
  
  int ans=0;
  for(auto p : m){
    int a = p.first;
    int b = p.second;
    //cout << a << " " << b << endl;
    if(a <= b){
      ans += b-a;
    }else{
      ans += b;
    }
  }
  
  cout << ans << endl;
  
  return(0);
}