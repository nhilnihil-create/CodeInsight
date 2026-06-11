#include <bits/stdc++.h>

using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define ll long long int

int main(){
  int N;
  cin>>N;
  double x[N];
  string S[N];
  double count=0; 
  rep(i,N){
    cin>>x[i]>>S[i];
      if(S[i][0]=='J')
	count+=x[i];
      else
	count+=x[i]*380000.0;

  }
  cout<<count<<endl;


  return 0;
}
