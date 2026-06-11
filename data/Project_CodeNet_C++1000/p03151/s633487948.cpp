#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
  int n,i,b,mc = 0;long long minus = 0;cin >> n;
  int a[n];
  for(i=0;i<n;i++) cin >> a[i];
  vector<int> plus;
  for(i=0;i<n;i++){
    cin >> b;
    if(a[i]-b>0) plus.push_back(a[i]-b);
    else if(a[i]-b<0){
      minus += a[i]-b;mc++;
    }
  }
  sort(plus.begin(),plus.end(),greater<int>());
  if(mc==0) cout << 0 << endl;
  else{
    for(i=0;i<plus.size();i++){
      minus += plus[i];
      if(minus>=0){
        cout << i+mc+1 << endl;break;
      }
    }
  }
  if(minus<0) cout << -1 << endl;
}
  
