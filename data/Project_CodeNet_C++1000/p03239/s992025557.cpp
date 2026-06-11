#include<bits/stdc++.h>
using namespace std;
#define rep0(i,n) for(i=0;i<n;i++)
#define test(a) cout << "*" << a << endl;
int main(){
  int i;
  int N,T;
  int c[1000];
  int t[1000];
  int costMin = 1001;
  
  cin >> N >> T;
  rep0(i,N){
    cin >> c[i] >> t[i];
    if(t[i]<=T){
        costMin = min(costMin,c[i]);
    }
  }
  if(costMin == 1001)
    cout << "TLE" << endl;
  else
    cout << costMin << endl;
 
}