#include<bits/stdc++.h>
#include <string> 

using namespace std;
const long long INF = 1e18;
#define PI 3.141592653589793
#define REP(i, n) for(int i = 0;i < n;++i)
long long N,Y;
long long A=0;
int main()
{
  string a;
  int l=0,c=0;
  vector<int>s;
  cin>>N>>Y;
  int a1=0,a2=0,a3=0;
  for(int i=0;i<=N;i++){
    for(int j=0;j<=N-i;j++){
      if(i*10000+j*5000+(N-i-j)*1000==Y){
        cout<<i<<" "<<j<<" "<<N-i-j;
        return 0;
      }
    }
  }
  cout<<"-1 -1 -1";
  
  return 0;
}