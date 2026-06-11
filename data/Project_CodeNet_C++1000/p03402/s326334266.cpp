#include <bits/stdc++.h> 

using namespace std; 
using ll = long long;
using ull = unsigned long long;
using pii = pair<int,int>; 

#define INF 100000000
#define MOD 10007
#define rng(a) a.begin(),a.end()
#define rrng(a) a.rbegin(),a.rend()

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int A,B;
  cin>>A>>B;
  //. A
  //# B
  
  //cout<<A<<" "<<B<<endl;;
  int h=100,w=100;
  vector<vector<char> >map(100,vector<char>(100));
  for(int i=0;i<100;i++){
    for(int j=0;j<100;j++){
      if(i%2)map[j][i]='.';
      else map[j][i]='#';
    }
  }
  for(int i=0;i<100;i++){
    map[0][i]='#';
  }
  for(int i=0;i<100;i++){
    map[99][i]='.';
  }

  vector<pii>ta,tb,a,b;
  pii af,bf;
  for(int i=0;i<49;i++){
    ta.push_back({99,2*i+1});
  }
  for(int i=1;i<50;i++){
    tb.push_back({0,2*i});
  }
  for(int i=0;i<49;i++){
    for(int j=0;j<50;j++){
      a.push_back({2*i+1,2*j});
    }
  }
  for(int i=1;i<50;i++){
    for(int j=0;j<50;j++){
      b.push_back({2*i,2*j+1});
    }
  }
  reverse(rng(a));

  A--;
  B--;
  for(int i=0;i<a.size();i++){
    if(B>0){
      map[a[i].first][a[i].second]='.';
      B--;
    }
    else break;
  }
  for(int i=0;i<a.size();i++){
    if(A>0){
      map[b[i].first][b[i].second]='#';
      A--;
    }
    else break;
  }
  for(int i=0;i<49;i++){
    if(A>=1&&B>=2){
      map[tb[i].first][tb[i].second]='.';
      A--;
      B-=2;
    }
    else break;
  }
  for(int i=0;i<49;i++){
    if(B>=1&&A>=2){
      map[ta[i].first][ta[i].second]='#';
      B--;
      A-=2;
    }
    else break;
  }
  //cout<<A<<" "<<B<<endl;

  cout<<100<<" "<<100<<endl;
  for(int i=0;i<100;i++){
    for(int j=0;j<100;j++){
      cout<<map[j][i];
    }
    cout<<endl;
  }
  return 0;
}
