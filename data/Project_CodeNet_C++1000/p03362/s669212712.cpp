#include<bits/stdc++.h>
using namespace std;

void sieve( vector<unsigned>& primes, unsigned n )
{
  if(n<2){ 
    return; 
  }
  primes.push_back(2);
  if(n<3){ 
    return; 
  }

  const unsigned lastIdx = (n-3)/2;
  vector<char> flag(lastIdx+1,1);
  for(unsigned i=0;i<=lastIdx;i++){
    if(flag[i]){
      unsigned p=2*i+3;
      primes.push_back(p);
      if(p<=n/p){
        for(unsigned j=i+p;j<=lastIdx;j+=p){
          flag[j]=0;
        }
      }
    }
  }
}

int main() {
  int k;
  cin>>k;
  vector<int> ans={};
  const unsigned n = 55555;
  vector<unsigned> primes;
  sieve(primes,n);
  vector<unsigned>::const_iterator it = primes.begin();
  while (it!=primes.end()){
    int p=*it;
    if(p%5==1) ans.push_back(p);
    it++;
  }

  for(int i=0;i<k;i++){
  	cout<<ans[i]<<" ";
  }
  cout<<endl;
}