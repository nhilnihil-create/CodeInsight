#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
using namespace std;
#define REP(i, limit) for(int i=0; i< limit; ++i)
#define LINT long long

int main(){
  int N;
  cin >> N;
  LINT a[N];
  LINT amax=0;
  REP(i, N) {
    cin >> a[i];
    amax=max(amax, a[i]);
  }

  if(N==2){
    cout << a[0] << " " << a[1] << endl;
    return 0;
  }
  
  LINT r=a[0]; //amax/2に最も近い値が入る
  REP(i, N){
    if(abs(r-amax/2)>abs(a[i]-amax/2)) r = a[i];
  }
  cout << amax << " " << r << endl;


  return 0;
}
