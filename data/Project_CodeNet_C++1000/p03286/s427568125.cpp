#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  ll n;
  cin >> n;
  if(n==0){
   cout << 0 << endl;
    return 0;
  }
  deque<ll>deq;
  while(n!=0){
    if(n%-2==0){
      deq.push_front(0);
    }
    if(n%-2!=0){
      n--;
      deq.push_front(1);
    }
    n/=-2;
  }
  while(deq.front()==0) deq.pop_front();
  while(deq.size()!=0){
    cout << deq.front();
    deq.pop_front();
  }
}
