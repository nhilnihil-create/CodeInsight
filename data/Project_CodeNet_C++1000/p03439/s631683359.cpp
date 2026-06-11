#include <bits/stdc++.h>
using namespace std;

int ok;
int ng;
string s;
string ok_s;
bool isOK(int mid){
  int tmp=mid-ok;
  if(tmp%2==0){
    if(s==ok_s) return true;
    else  return false;
  }
  else{
    if(s==ok_s) return false;
    else  return true;
  }
}

int main(){
  int N;
  cin >> N;

  ok=0;
  ng=N;
  cout << 0 << endl;
  cin >> ok_s;
  if(ok_s=="Vacant")  return 0;

  while(1){
    int mid=(ok+ng)/2;
    cout << mid << endl;
    cin >> s;
    if(s=="Vacant") break;
    if(isOK(mid)){
      ok=mid;
      ok_s=s;
    }
    else ng=mid;
  }

  return 0;
}