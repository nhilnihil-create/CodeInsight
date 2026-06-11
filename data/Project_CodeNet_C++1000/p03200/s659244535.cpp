#include <bits/stdc++.h>
using namespace std;

#define froop1(a,n) for(int i = a;i < n;i++)
#define froop2(a,n) for(int i = a;i > n;i--)

#define ll long long

#define pq(name,type) priority_queue<type> name
#define vec(name,type,length,value) vector<type> name(length,value)
#define vec2(name,type,length,width,value) vector<vector<type>> name(length,vector<type>(width,value));

int main(){
	string N;
  cin >> N;
  ll sl = N.length();
  ll count = 0,c1 = 0;
  froop1(0,sl){
   if(N[i] == 'B') c1++;
  else
    count += c1;
  
  }
  cout << count << endl;

return 0;
}