#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
  ll n;
  cin >> n;
  bool exist=false;
  ll groups = 0, crr = 0;
  queue<ll> q, tpq;
  if(n>2){
    for(ll i=2;i<2*n;i++){
      if((2*n)%i!=0) continue;
      else{
        if(abs((2*n)/i - i) == 1) {
          groups = i;
          exist = true;
          break;
        }
      }
    }
  }

  if(exist){
    cout << "Yes" << endl;
    cout << 2*n/groups << endl;
    for(ll i=0;i<2*n/groups;i++){
      ll cnt = 0;
      cout << groups << " ";
      if(i == 0){
        for(crr=1;crr<=groups;crr++){
          cout << crr << " ";
        }
        cout << endl;
        q.push(1);
        continue;
      }
      while(!q.empty()){
        cnt += 1;
        cout << q.front() << " ";
        tpq.push(q.front() + 1);
        q.pop();
      }
      ll tar = crr + groups - cnt; 
      tpq.push(crr);
      for(;crr < tar; crr++){
          cout << crr << " ";
      }
      cout << endl;
      q = tpq;
      while(!tpq.empty()){
        tpq.pop();
      }
    }
  }else{
	if(n == 1){
      cout << "Yes" << endl;
      cout << 2 << endl;
      cout << 1 << " " << 1 << endl;
      cout << 1 << " " << 1 << endl;
    }else{
      cout << "No" << endl;
    }
  }
}