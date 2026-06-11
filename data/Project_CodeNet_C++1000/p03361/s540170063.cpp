#include<bits/stdc++.h>
using namespace std;
int main(){
  int h,w;
  cin>>h>>w;
  vector<string> s(h);
  for(int i=0;i<h;i++)
    cin>>s.at(i);
  vector<int> y={-1,0,1,0};
  vector<int> x={0,1,0,-1};
  bool f=1;
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      if(s.at(i).at(j)=='#'){
        f=0;
        for(int k=0;k<y.size();k++){
          int ik=i+y.at(k);
          int jk=j+x.at(k);
          if(0<=ik&&ik<h&&0<=jk&&jk<w&&s.at(ik).at(jk)=='#')
            f=1;
        }
      }
      if(!f){
        i=h;
        j=w;
      }
    }
  }
  cout<<(f?"Yes":"No")<<endl;
}