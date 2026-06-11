#include<bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(),v.end()
#define puts(i) cout << i << endl
#define INF INT_MAX
#define INFL LLONG_MAX
typedef long long ll;
using namespace std;


int main(){
  ll n;
  cin >> n;

std::vector<ll> a(n);
rep(i,n) cin >> a.at(i);

sort(all(a));

ll number=a.at(0);
ll del=0,count=0,N=0;
ll i;
for(i=0;i<n;i++){
  if(number==a.at(i)){
    count++;
  }else{
    if(count>number){
      del+=count-number;
    }
    else if(count<number){
      del+=count;
    }
    number=a.at(i);
    count=1;
  }
}

if(count>number){
  del+=count-number;
}
else if(count<number){
  del+=count;
}

cout << del << endl;



}