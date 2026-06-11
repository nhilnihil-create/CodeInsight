#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define rep1(i, n) for(int i=1; i<(int)(n); i++)
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> wi;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int s;
  cin >> s;
  int a=s/100, b=s%100;
  if(1<=a&&a<=12){
    if(1<=b&&b<=12)cout << "AMBIGUOUS" << endl;
    else cout << "MMYY" << endl;
  }
  else{
    if(1<=b&&b<=12)cout << "YYMM" << endl;
    else cout << "NA" << endl;
  }

  return 0;
}