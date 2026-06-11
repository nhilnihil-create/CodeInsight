#define rep(i,n) for (int i=0;i<n;i++)
#include <vector>
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const long long INF = 1LL<<60;

int main(){
  
  int H,W,count=0;
 // bool torf=false;
  cin >> H >> W;
  
  pair<int,int> p;
  vector<vector<char>> A(H,vector<char>(W));
  vector<vector<int>> B(H,vector<int>(W,0));
  deque<pair<int,int>> d;
  
  
  rep(i,H){
    rep(j,W){
      cin >> A.at(i).at(j);
      if(A.at(i).at(j)=='#'){
        p=make_pair(i,j);
        d.push_back(p);
      }
    }
  }

  while(!(d.empty())){
    
    if(d.front().second+1<W && A.at(d.front().first).at(d.front().second+1)=='.'){
      A.at(d.front().first).at(d.front().second+1)='#';
      B.at(d.front().first).at(d.front().second+1)=B.at(d.front().first).at(d.front().second)+1;
      p=make_pair(d.front().first,d.front().second+1);
      d.push_back(p);
      //torf=true;
    }
    if(d.front().second-1>=0 && A.at(d.front().first).at(d.front().second-1)=='.'){
      A.at(d.front().first).at(d.front().second-1)='#';
      B.at(d.front().first).at(d.front().second-1)=B.at(d.front().first).at(d.front().second)+1;
      p=make_pair(d.front().first,d.front().second-1);
      d.push_back(p);
     // torf=true;
    }
    if(d.front().first-1>=0 && A.at(d.front().first-1).at(d.front().second)=='.'){
      A.at(d.front().first-1).at(d.front().second)='#';
      B.at(d.front().first-1).at(d.front().second)=B.at(d.front().first).at(d.front().second)+1;
      p=make_pair(d.front().first-1,d.front().second);
      d.push_back(p);
      //torf=true;
    }
    if(d.front().first+1<H && A.at(d.front().first+1).at(d.front().second)=='.'){
      A.at(d.front().first+1).at(d.front().second)='#';
      B.at(d.front().first+1).at(d.front().second)=B.at(d.front().first).at(d.front().second)+1;
      p=make_pair(d.front().first+1,d.front().second);
      d.push_back(p);
      //torf=true;
    }
    
   // cout << d.front().first << d.front().second <<  endl;
    d.pop_front();
  //  if(torf==true)
    //count++;
    
   // torf=false;
    
  }
  rep(i,H){
    rep(j,W)
      count=max(B.at(i).at(j),count);

  }
  
  
  cout << count << endl;
  
}