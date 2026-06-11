#include<bits/stdc++.h>
using namespace std ;

int main(){
  int h,w,n,s_h,s_w ;
  cin >> h >> w >> n >> s_h >> s_w ;
  string s,t ;
  cin >> s >> t ;
  bool up,down,right,left ;
  up = down = right = left = false ;
  int place_u,place_d,place_r,place_l ;
  place_u = place_d = s_h ;
  place_r = place_l = s_w ;
  for(int i=0;i<n;i++){
    if(s.at(i)=='U'){
      place_u-- ;
      if(place_u==0){
        cout << "NO" << endl ;
        return 0 ;
      }
    }
    if(s.at(i)=='D'){
      place_d++ ;
      if(place_d==h+1){
        cout << "NO" << endl ;
        return 0 ;
      }
    }
    if(s.at(i)=='R'){
      place_r++ ;
      if(place_r==w+1){
        cout << "NO" << endl ;
        return 0 ;
      }
    }
    if(s.at(i)=='L'){
      place_l-- ;
      if(place_l==0){
        cout << "NO" << endl ;
        return 0 ;
      }
    }
    if(t.at(i)=='U'){
      place_d-- ;
      if(place_d==0)
        place_d++ ;
    }
    if(t.at(i)=='D'){
      place_u++ ;
      if(place_u==h+1)
        place_u-- ;
    }
    if(t.at(i)=='R'){
      place_l++ ;
      if(place_l==w+1)
        place_l-- ;
    }
    if(t.at(i)=='L'){
      place_r-- ;
      if(place_r==0)
        place_r++ ;
    }
  }
  cout << "YES" << endl ;
}