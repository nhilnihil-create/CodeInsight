#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef pair<int, int> P;

int main(){
  ll A, B;
  cin >> A  >> B;
  ll ans;
  if(A % 2 == 0 && B % 2 == 0){
    //A: even B:even
    if(((B-A)/2)%2 == 0){
      ans = 0 ^ B;
    }else{
      ans = 1 ^ B;
    }
  }else if(A % 2 == 0 && B % 2 != 0){
    //A:even B:odd
    if(((B-A+1)/2)%2 == 0){
      ans = 0;
    }else{
      ans = 1;
    }
  }else if(A % 2 != 0 && B % 2 == 0){
    //A:off B:even
    if(((B-A-1)/2)%2 == 0){
      ans = A ^ B;
    }else{
      ans = A ^ 1 ^ B;
    }
  }else{
    //A, B:odd
    if(((B-A)/2)%2 == 0){
      ans = A;
    }else{
      ans = A ^ 1;
    }
  }
  cout << ans << endl;

}
