#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
typedef long long ll;

int main(){
  int N,Q;
  string S;
  cin >> N >> Q;
  cin >> S;
  int l[Q],r[Q];
  for(int i=0;i<Q;i++){
    cin >> l[i] >> r[i];
  }
  int sum[N];
  for(int i=0;i<N;i++){
    sum[i]=0;
  }
  for(int i=0;i<N-1;i++){
    if(S[i]=='A' && S[i+1]=='C') sum[i+1]=sum[i]+1;
    else sum[i+1]=sum[i];
  }
  for(int n=0;n<Q;n++){
    cout << sum[r[n]-1]-sum[l[n]-1] << endl;
  }
}
