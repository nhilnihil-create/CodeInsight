#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>; // intの1次元の型に vi という別名をつける
using vvi = vector<vi>; // intの2次元の型に vvi という別名をつける
 
int main() {
  int n, odd, even;
  cin >> n;
  vi ocnt(100001);
  vi ecnt(100001);
  rep(i,n/2){
    cin >> odd;
    ocnt.at(odd) ++;
    cin >> even;
    ecnt.at(even) ++;
  }
  
  odd=0, even=0;
  int odd2=0, even2=0, oddc=0, evenc=0;
 
  rep(i,100001){
    if (i == 0 ) continue;
    if(odd2 <= ocnt.at(i) && odd >= ocnt.at(i)){
      odd2 = ocnt.at(i);
    }
    else if(odd < ocnt.at(i)){
      odd2 = odd;
      odd = ocnt.at(i);
      oddc = i;
    }
    if(even2 <= ecnt.at(i) && even >= ecnt.at(i)){
      even2 = ecnt.at(i);
    }
    else if(even < ecnt.at(i)){
      even2 = even;
      even = ecnt.at(i);
      evenc = i;
    }
  }
  
  int ans = 0 ;
  if (oddc==evenc) ans = max(odd+even2,odd2+even);
  else ans = odd+even;
      
  cout << n-ans << endl;  
  return 0;
}