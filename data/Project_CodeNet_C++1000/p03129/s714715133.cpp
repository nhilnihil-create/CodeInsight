#include<bits/stdc++.h>
using namespace std;

int main() {
  int a,b,cnt;cin >> a >> b;
  if(a%2!=0){
    cnt = a/2+1;
  }else{
    cnt = a/2;
  }

  if(cnt<b){
    cout << "NO" << endl;
  }else{
    cout << "YES" << endl;
  }
}