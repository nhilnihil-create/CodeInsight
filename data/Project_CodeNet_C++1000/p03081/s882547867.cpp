#include<bits/stdc++.h>
using namespace std;
int N,Q;
string s;
vector<char> t(200009),d(200009);
int lb,ub,LB,UB;

bool C(int x){
  for(int i=0;i<Q;i++){
    if(s[x]==t[i]){
      if(d[i]=='L')x--;
      else x++;
    }
    if(x<0)return false;
    if(x>=N)return true;;
  }
  return true;
}

bool Cc(int x){
  for(int i=0;i<Q;i++){
    if(s[x]==t[i]){
      if(d[i]=='L')x--;
      else x++;
    }
    if(x>=N)return false;
    if(x<0)return true;
  }
  return true;
}

int main(){
  cin >> N >> Q >> s;
  for(int i=0;i<Q;i++)cin >> t[i] >> d[i];
  lb=-1,ub=N,LB=-1,UB=N+1;
  while(ub-lb>1){
    int mid=(ub+lb)/2;
    if(C(mid))ub=mid;
    else lb=mid;
  }
  while(UB-LB>1){
    int mid=(UB+LB)/2;
    if(Cc(mid))LB=mid;
    else UB=mid;
  }
  //cout << LB << endl;
  //cout << ub << endl;
  cout << LB-ub+1 << endl;
}