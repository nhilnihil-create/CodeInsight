#include <bits/stdc++.h>
using namespace std;
 
#define froop1(a,n) for(int i = a;i < n;i++)
#define froop2(a,n) for(int i = a;i > n;i--)
 
#define ll long long
 
#define pq(name,type) priority_queue<type> name
#define vec(name,type,length,value) vector<type> name(length,value)
#define vec2(name,type,length,width,value) vector<vector<type>> name(length,vector<type>(width,value));
 
int main(){
	ll N,count1 = 0,sum = 0,min = 99999999999;
  cin >> N;
  vec(a,ll,N,0);
  froop1(0,N){
   cin >> a.at(i); 
    if(a.at(i) < 0){
      count1++;
    }
    sum += abs(a.at(i));
    if(abs(a.at(i)) < min){
      min = abs(a.at(i));
    }
  }
  if(count1 % 2 == 0){
    cout << sum << endl;
  }else{
    cout << sum - 2*min << endl;
  }
}