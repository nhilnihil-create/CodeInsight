#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main(){
  int N,t;
  long long sum=0;
  vector<long long> A,B;
  int neg_count=0;
  multiset<long long,greater<long long>> pos;
  cin >> N;
  for(int i=0;i<N;i++) {
    cin >> t;
    A.push_back(t);
  }
  for(int i=0;i<N;i++){
    cin >> t;
    if(t>A[i]){
      neg_count++;
      sum+=t-A[i];
    }else if(t<A[i]){
      pos.insert(A[i]-t);
    }
  }
  int pos_count=0;
  for(auto itr=pos.begin();itr!=pos.end();itr++){
    if(sum<=0) break;
    sum-=*itr;
    pos_count++;
  }
  if(sum<=0){
    cout << pos_count+neg_count << endl;
  }else{
    cout << -1 << endl;
  }
   
}
  