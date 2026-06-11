#include <bits/stdc++.h>
 
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(obj) (obj).begin(), (obj).end()
#define bit(n) (1LL << (n))
 
typedef long long ll;

using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  int d;
  cin>>d;
  
  if(d==25){
    cout<<"Christmas";
  }else if(d==24){
    cout<<"Christmas Eve";
  }else if(d==23){
    cout<<"Christmas Eve Eve";
  }else if(d==22){
    cout<<"Christmas Eve Eve Eve";
  }
    
  return 0;
}