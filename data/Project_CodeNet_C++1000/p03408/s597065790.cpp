#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,m;
  cin >> n;
  vector<string> b(n);
  for(int i=0; i<n; i++){
    cin >> b.at(i);
  }
  cin >> m;
  vector<string> r(m);
  for(int i=0; i<m; i++){
    cin >> r.at(i);
  }
  
  int max_count = 0;
  int bcount=0, rcount=0;
  for(int i=0; i<n; i++){
    for(int j=i; j<n; j++){
      if(b.at(i) == b.at(j)){
        bcount +=1;
      }
    }
    for(int k=0; k<m; k++){
      if(b.at(i) == r.at(k)){
        rcount +=1;
      }
    }
    int check = bcount - rcount;
    if(max_count < check){
      max_count = check;
    }
    bcount=0;
    rcount=0;
  }
  cout << max_count << endl;
}