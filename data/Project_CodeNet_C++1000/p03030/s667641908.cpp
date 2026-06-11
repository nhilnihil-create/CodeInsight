#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; 
    cin>>N;

  vector<tuple< string,int,int>> a;
  for(int i=0; i<N;i++){
      int x;
      string y;
      cin>>y>>x;

      a.push_back(make_tuple(y, x*-1,i));
  }
  sort(a.begin(), a.end());


  for(tuple<string,int,int>l:a){
      int j;
      tie(ignore,ignore,j)=l;
      cout<<j+1<<endl;


  }
  
}
