#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
int main(){
  int s;
  cin >> s;
  ll p=s/100;
  ll q=s-p*100;
  if(p>0 &&p<13 && q>0 && q<13){
    cout <<"AMBIGUOUS";
  }else if( p>0 &&p<13 ){
    cout << "MMYY";
  }else if(q>0&&q<13){
    cout << "YYMM";
  }else{
    cout << "NA";
  }
}

