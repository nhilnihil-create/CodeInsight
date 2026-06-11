#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0;i<n;i++)
#define erep(i,n) for(int i = 0;i<=n;i++)
#define rep1(i,n) for(int i = 1;i<n;i++)
#define erep1(i,n) for(int i = 1;i<=n;i++)
typedef long long ll;
#define vint vector<int>
#define vvint vector<vector<int>>
#define vstring vector<string>
#define vdouble vector<double>
#define vll vector<ll>:
#define vbool vector<bool>
#define INF 1101010101010101010
#define MOD 1000000007
#define int long long
using P = pair<int,int>;

signed main(){
  int h,w;
  cin >> h >> w;
  vvint mass(h,vint(w));
  rep(i,h) rep(j,w) cin >> mass[i][j];
  bool judge = false;
  int count = 0;
  vector<vector<int>> ans(300000,vint(4)); 
  rep(i,h){
    if(i % 2 == 0){
      rep(j,w){
        if(i != h-1 || j != w-1){
          if(mass[i][j] % 2 == 1 && !(judge)){
            judge = true;
            if(j == w-1){
              ans[count][0] = i+1;
              ans[count][1] = j+1;
              ans[count][2] = i+2;
              ans[count][3] = j+1;
            }
            else{
              ans[count][0] = i+1;
              ans[count][1] = j+1;
              ans[count][2] = i+1;
              ans[count][3] = j+2;            
            }
            count++;
          }
          else if(mass[i][j] % 2 == 1 && judge){
            judge = false;
          }
          else if(mass[i][j] % 2 == 0 && judge){
            if(j == w-1){
              ans[count][0] = i+1;
              ans[count][1] = j+1;
              ans[count][2] = i+2;
              ans[count][3] = j+1;
            }
            else{
              ans[count][0] = i+1;
              ans[count][1] = j+1;
              ans[count][2] = i+1;
              ans[count][3] = j+2;            
            }
            count++;
          }
        }
      }
    }
    else{
      for(int j = w-1;j >= 0;j--){
        if(i != h-1 || j != 0){
          if(mass[i][j] % 2 == 1 && !(judge)){
            judge = true;
            if(j == 0){
              ans[count][0] = i+1;
              ans[count][1] = 1;
              ans[count][2] = i+2;
              ans[count][3] = 1;
            }
            else{
              ans[count][0] = i+1;
              ans[count][1] = j+1;
              ans[count][2] = i+1;
              ans[count][3] = j;            
            }
            count++;
          }
          else if(mass[i][j] % 2 == 1 && judge){
            judge = false;
          }
          else if(mass[i][j] % 2 == 0 && judge){
            if(j == 0){
              ans[count][0] = i+1;
              ans[count][1] = 1;
              ans[count][2] = i+2;
              ans[count][3] = 1;
            }
            else{
              ans[count][0] = i+1;
              ans[count][1] = j+1;
              ans[count][2] = i+1;
              ans[count][3] = j;            
            }
            count++;
          }
        }
      }
    }
  }
  cout << count << endl;
  rep(i,count){
    cout << ans[i][0] << " " << ans[i][1] << " " << ans[i][2] << " " << ans[i][3] << endl;
  }
}