#include<iostream>
using namespace std;
int main(){
  int n,h,w,cnt=0;
  cin >> n >> h >> w;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(i+h<=n&&j+w<=n)cnt++;
    }
  }
  cout << cnt << endl;
}
