#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef vector<int> VI;
ll mm=1000000000;ll MM=mm+7;
#define rep(i, n) for(int i=0;i<n;i++)
#define PI 3.141592653589793
 
int dx[8] = {1,1,1,0,0,-1,-1,-1};
int dy[8] = {-1,0,1,-1,1,-1,0,1};
   
int main(){
  int h,w;
  cin >> h >> w;
  vector<vector<char>> s(h+2,vector<char>(w+2));
  for(int i=1;i<=h;i++){
    for(int j=1;j<=w;j++){
        cin >> s.at(i).at(j);
    }
  }
  for(int i=1;i<=h;i++){
    for(int j=1;j<=w;j++){
      if(s.at(i).at(j)=='.'){
        int cnt=0;
       rep(k,8){
         int H=i+dy[k];
         int W=j+dx[k];
          if(s.at(H).at(W)=='#')cnt++;
       }
       char nw=char('0'+cnt);
       s.at(i).at(j)=nw;
      }
    }
  }
  for(int i=1;i<=h;i++){
    for(int j=1;j<=w;j++){
        cout << s.at(i).at(j);
    }
    cout << endl;
  }


} 
    