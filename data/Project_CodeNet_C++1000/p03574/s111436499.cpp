#include<bits/stdc++.h>
using namespace std;
 
signed main()
{
  int h,w; cin >> h >> w;
  vector<string> v(h);
  for(int i=0; i<h; ++i){
    cin >> v[i];
  }

  for(int i=0; i<h; ++i){
    for(int j=0; j<w; ++j){
      int sum = 0;
      if(v[i][j]=='#') {cout << '#'; continue;}

      if(i!=0 && j!=0) {if(v[i-1][j-1]=='#') ++sum;}
      if(i!=0) {if(v[i-1][j]=='#') ++sum;}
      if(i!=0 && j!=w-1) {if(v[i-1][j+1]=='#') ++sum;}

      if(j!=0) {if(v[i][j-1]=='#') ++sum;}
      if(j!=w-1) {if(v[i][j+1]=='#') ++sum;}

      if(i!=h-1 && j!=0) {if(v[i+1][j-1]=='#') ++sum;}
      if(i!=h-1) {if(v[i+1][j]=='#') ++sum;}
      if(i!=h-1 && j!=w-1) {if(v[i+1][j+1]=='#') ++sum;}

      cout << sum;
    }
    cout << "\n";
  }
}