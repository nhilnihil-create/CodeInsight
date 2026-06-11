#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef pair<int,tuple<int,int,int>> pti;
#define rep(i,s,n) for(int i=(int)(s);i<(int)(n);i++)

int S;
int main(){
  cin >> S;
  int xx = S%100;
  int yy = S/100;
  bool YYMM,MMYY;
  YYMM = (xx>=1&&xx<=12);
  MMYY = (yy>=1&&yy<=12);
  if(YYMM&&MMYY) cout << "AMBIGUOUS" << endl;
  if(YYMM&&!MMYY) cout << "YYMM" << endl;
  if(!YYMM&&MMYY) cout << "MMYY" << endl;
  if(!YYMM&&!MMYY) cout << "NA" << endl;
}