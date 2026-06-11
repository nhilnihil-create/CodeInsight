#include <iostream>
using namespace std;
#define INF 1000000000
#define rep(i,a) for(i=0;i<a;++i)
int i;
int main(){
  int N;
  cin >> N;
  int a[110];
  rep(i,N) cin >> a[i];
  int max = 1;
  int min = INF;
  rep(i,N){
    if(a[i] > max) max = a[i];
    if(a[i] < min) min = a[i];
  }
  cout << max-min << endl;
}