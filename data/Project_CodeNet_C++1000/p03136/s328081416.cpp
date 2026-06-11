#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin>>N;
  multiset<int> L;
  for (int i=0; i<N; i++){
    int x;
    cin>>x;
    L.insert(x);
  }
  int longest=*L.rbegin();
  L.erase(L.find(*L.rbegin()));
  int other_sum=accumulate(L.begin(),L.end(),0);
  if (other_sum>longest){
    cout<<"Yes"<<endl;
  }else{
    cout<<"No"<<endl;
  } 
}
  