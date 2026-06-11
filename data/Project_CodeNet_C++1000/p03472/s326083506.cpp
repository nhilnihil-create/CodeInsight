#include <bits/stdc++.h>
using namespace std;
 
#define froop1(a,n) for(int i = a;i < n;i++)
#define froop2(a,n) for(int i = a;i > n;i--)
 
#define ll long long
 
#define pq(name,type) priority_queue<type> name
#define vec(name,type,length,value) vector<type> name(length,value)
#define vec2(name,type,length,width,value) vector<vector<type>> name(length,vector<type>(width,value));
 
int main(){
	ll N,hp;
  cin >> N >> hp;
  vec(normal,ll,N,0);
  vec(throwing,ll,N,0);
  vector<ll> c;
  ll nmax = 0,tm = 0,n = 0;
  froop1(0,N){
    cin >> normal.at(i) >> throwing.at(i);
  }
  froop1(0,N){
    if(nmax < normal.at(i)){
      nmax = normal.at(i);
      tm = throwing.at(i);
      n = i;
    }else if(nmax == normal.at(i) && throwing.at(n) > throwing.at(i)){
      nmax = normal.at(i);
      tm = throwing.at(i);
      n = i;
    }
}
ll count = 0;
  froop1(0,N){
    if(throwing.at(i) > nmax && i != n){
      c.push_back(throwing.at(i));
  }
}
  sort(c.begin(),c.end(),greater<long long>());
  froop1(0,c.size()){
   if(hp <= 0) break;
    hp -= c.at(i);
    count++;
  }
 while(hp > 0){
  if(hp <= throwing.at(n)){
    hp -= throwing.at(n);
  }else{
    hp -= normal.at(n);
  }
   count++;
 }
  cout << count << endl;
}