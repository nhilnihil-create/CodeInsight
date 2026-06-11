#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;


int main(){
  int Q;
  vector<int> ls,rs,nums;
  set<int> primes;
  int Nmax=0,l,r;
  cin >> Q;
  for(int i=0;i<Q;i++){
    cin >> l >> r;
    if(r>Nmax) Nmax=r;
    ls.push_back(l);
    rs.push_back(r);
  }
  primes.insert(primes.end(),2);
  primes.insert(primes.end(),3);
  if(primes.find( (3+1)/2)!=primes.end()) nums.push_back(3);
  for(int i=6;i<=Nmax;i+=6){
    int flag1=1,flag2=1;
    for(auto itr=primes.begin();itr!=primes.end();++itr){
      if((i-1)%*itr==0){
        flag1 = 0;
      }
      if((i+1)%*itr==0){
        flag2 = 0;
      }
    }
    if ( (flag1==1) ){
      primes.insert(primes.end(),i-1);
      if(primes.find(i/2)!=primes.end()) nums.push_back(i-1);      
    }
    if ( (flag2==1) ){
      primes.insert(primes.end(),i+1);
      if(primes.find(i/2+1)!=primes.end()) nums.push_back(i+1);      
    }
  }
  sort(nums.begin(),nums.end());
  for(int i=0;i<Q;++i){
    cout << upper_bound(nums.begin(),nums.end(),rs[i])-lower_bound(nums.begin(),nums.end(),ls[i]) << endl;
  }
}
  