#define _GLIBCXX_DEBUG
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <cstdint>
#include <cstdio>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <cctype>
#include <cmath>

using namespace std;
int main(){
  vector<long long int> p,q,r;
  long long int n,s=0,k=0,c=0;
  cin>>n;
  for(int i=0;i<n;i++){
    int x;
    cin>>x;
    p.push_back(x);
  }
  for(int i=0;i<n;i++){
    int x;
    cin>>x;
    q.push_back(x);
  }
  for(int i=0;i<n;i++){
    int x;
    x=p.at(i)-q.at(i);
    s+=x;
    r.push_back(x);
  }
   sort(r.begin(),r.end());
 reverse(r.begin(),r.end());
  if(s<0){
    cout<<-1;
  }
 
  else{
    for(int p:r){
    if(p<0){
      k+=p;
      c++;
    }
  }
    for(int p:r){
    if(k<0){
      k+=p;
      c++;
    }
  }}
    if(s>=0){cout<<c;}
}
