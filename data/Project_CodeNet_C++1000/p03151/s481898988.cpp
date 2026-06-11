#include <bits/stdc++.h>
using namespace std;

#define froop1(a,n) for(int i = a;i < n;i++)
#define froop2(a,n) for(int i = a;i > n;i--)

#define ll long long

#define pq(name,type) priority_queue<type> name
#define vec(name,type,length,value) vector<type> name(length,value)
#define vec2(name,type,length,width,value) vector<vector<type>> name(length,vector<type>(width,value));

int main(){
	long long N,sum = 0,count = 0,S = 0;
  int sw = 0;
  cin >> N;
  vec(a,long long,N,0);
  vec(b,long long,N,0);
  vec(dist,long long,N,0);
  froop1(0,N){
   cin >> a.at(i);
    dist.at(i) = a.at(i);
  }
  
  froop1(0,N){
    cin >> b.at(i);
    if(a.at(i) < b.at(i)){
      sw = 1;
      count++;
    }
    dist.at(i) -= b.at(i);
    if(dist.at(i) >= 0){
    sum += dist.at(i);
    }
    if(b.at(i) - a.at(i) > 0){
    S += b.at(i) - a.at(i);
    }
  }
  
  if(sw == 0){
    cout << 0 << endl;
    return 0;
  }
  if(sum < S){
    cout << -1 << endl;
    return 0;
  }
  
  sort(dist.begin(),dist.end(),greater<long long>());
  long long c = 0,i = 0;
  while(S > 0){
   S -= dist.at(i); 
    i++;
    c++;
  }
	cout << count + c << endl;
return 0;
}