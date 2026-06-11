#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int N;
  cin>>N;
  vector<int>c(N-1);
  vector<int>s(N-1);
  vector<int>f(N-1);
  rep(i,N-1){
    cin>>c.at(i)>>s.at(i)>>f.at(i);
  }
  vector<int>a(N);
  a.at(N-1)=0;
  rep(i,N-1){
    a.at(i)+=s.at(i);
    rep2(j,i,N-2){
      a.at(i)+=c.at(j);
      
      if(s.at(j+1)>a.at(i)){
        a.at(i)=s.at(j+1);
      }
      else{
        if((a.at(i)-s.at(j+1))%f.at(j+1)!=0){
          a.at(i)+=f.at(j+1)-(a.at(i)-s.at(j+1))%f.at(j+1);
        }
      }
    }
    a.at(i)+=c.at(N-2);
  }
  for(int i=0; i<N;i++){
    cout<<a.at(i)<<endl;
  }
}