#include<bits/stdc++.h>
using namespace std;

int main(){
  int h,w;
  cin >> h >> w;
  vector<string> str(h);
  for(int i=0;i<h;i++){
    cin >> str.at(i);
  }
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      if(str.at(i).at(j)=='#'){
        cout << '#';
        continue;
      }
      int cnt=0;
      if(i-1>=0&&j-1>=0&&str.at(i-1).at(j-1)=='#'){cnt++;}
      if(i-1>=0&&str.at(i-1).at(j)=='#'){cnt++;}
      if(i-1>=0&&j+1<w&&str.at(i-1).at(j+1)=='#'){cnt++;}
      if(j-1>=0&&str.at(i).at(j-1)=='#'){cnt++;}
      if(j+1<w&&str.at(i).at(j+1)=='#'){cnt++;}
      if(i+1<h&&j-1>=0&&str.at(i+1).at(j-1)=='#'){cnt++;}
      if(i+1<h&&str.at(i+1).at(j)=='#'){cnt++;}
      if(i+1<h&&j+1<w&&str.at(i+1).at(j+1)=='#'){cnt++;}
	  cout << cnt;
    }
    cout << endl;
  }
}
