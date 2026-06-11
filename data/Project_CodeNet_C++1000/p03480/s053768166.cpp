#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
using namespace std;

string S;
int N;
int abl[100001]; //-1:不可　0：未定　１：可能

void bs(int a, int b){
  int p = (a + b) / 2;
  if(abl[p]!=0) return;
  //K = pでできるか検査
  int s = N - p;
  int t = p - 1;
  bool is_same = true;
  for(int i=s;i<t;i++){
    if(S[i]!=S[i+1]) is_same = false;
  }
  if(is_same){
    abl[p] = 1;
    bs(p+1,b);
  }
  else{
    abl[p] = -1;
    bs(a,p-1);
  }
  return;
}

int main(){
  cin >> S;
  N = S.size();
  fill(abl,abl+100001,0);

  bs(0,N);

  if(abl[N]==1){
    cout << N << endl;
    return 0;
  }

  for(int i=0;i<N;i++){
    if(abl[i] == 1 && abl[i+1] == -1){
      cout << i << endl;
    }
  }

  /*for(int i=0;i<=N;i++){
    cout << i << " " << abl[i] << endl;
  }*/

  return 0;
}