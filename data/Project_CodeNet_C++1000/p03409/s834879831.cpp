#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<pair<int,int> >blue(n);
  vector<pair<int,int> >red(n);

  vector<bool>blueChk(n,true);
  vector<bool>redChk(n,true);

  int i,j;
  for(i=0;i<n;i++){
    cin >> red[i].first >> red[i].second;
  }
  for(i=0;i<n;i++){
    cin >> blue[i].first >> blue[i].second;
  }
  sort(red.begin(),red.end());
  sort(blue.begin(),blue.end());
  int ans = 0;
  for(i=0;i<n;i++){
    if(blueChk[i]){
      int tmpY = -1;
      int tmp = -1;
      for(j=n-1;j>=0;j--){
        if(redChk[j] && red[j].first<blue[i].first && red[j].second<blue[i].second){
          if(tmpY < red[j].second){
            tmpY = red[j].second;
            tmp = j;
          }
        }
      }
      if(tmp!=-1){
        ans++;
        redChk[tmp]=false;
      }
    }
  }
  cout<<ans<<endl;
}
