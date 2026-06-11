#include <bits/stdc++.h>
using namespace std;
#include<cstdlib>

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
typedef long long ll;

bool check(int time, int nextx, int nexty){
  if(nextx+nexty<=time && (nextx+nexty)%2==time%2) return true;
  else return false;
}

int main(){
  int n;
  cin >> n;

  vector<tuple<int,int,int>> trip;
  trip.push_back(make_tuple(0,0,0));
  rep(i,n){
    int t,x,y;
    cin >> t >> x >> y;
    trip.push_back(make_tuple(t,x,y));
  }
  
  //rep(i,n+1) cout << get<0>(trip.at(i)) << " " << get<1>(trip.at(i)) << " " << get<2>(trip.at(i)) << endl;

  rep(i,n){
    int dt = get<0>(trip.at(i+1)) - get<0>(trip.at(i));
    int dx = abs(get<1>(trip.at(i)) - get<1>(trip.at(i+1)));
    int dy = abs(get<2>(trip.at(i)) - get<2>(trip.at(i+1)));
    if(!check(dt, dx, dy)){cout<<"No"; return 0;}
    //cout << dt << " " << dx << " " << dy << endl;
  }

  cout<<"Yes";
  
}