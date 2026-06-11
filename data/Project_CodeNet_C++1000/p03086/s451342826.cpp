#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1000000007;


int main() {
  string s;
  cin >> s;
  int size=s.size();
  vector<int> a(size);
  for(int i=0;i<size;i++){
    if(s.at(i)=='A' || s.at(i)=='C' ||
       s.at(i)=='G' || s.at(i)=='T'){
         a.at(i)=1;
       }
  }
  int k=0;
  priority_queue<int> pq;
  for(int i=0;i<size;i++){
    if(a.at(i)==1){
      if(i==size-1){
        k++;
        pq.push(k);
      }
      else
        k++;
    }
    else{
      pq.push(k);
      k=0;
    }
  }
  cout << pq.top() << endl;
}

