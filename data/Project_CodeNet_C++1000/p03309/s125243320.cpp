#include<bits/stdc++.h>
#include<vector>
using namespace std;
#define ll long long
#define rep0(i,n) for(i=0;i<n;i++)
#define test(a) cout << "*" << a << endl
int main(){
  ll i,j;
  ll n;
  ll a[200000];
  ll a2[200000];
  ll aMai[200000];
  ll b;
  ll sum=0;
  ll countA=0;
  ll countB=0;
 
  cin >> n;
  rep0(i,n){
    cin >> a[i];
    a2[i] = i+1;
    aMai[i] = a[i] - a2[i];
    if(aMai[i]<0){
      aMai[i] = (-1) * aMai[i];
    }
  }
  vector<ll> vec(n);
  
  rep0(i,n){
    vec[i] = a[i]-a2[i];
  }
  
  sort(vec.begin(),vec.end());
  
  //rep0(i,n) test(vec[i]);
  
  if(n%2==0 && vec[(n+1)/2-1] != vec[(n+1)/2]){
    rep0(i,n){
      if(vec[i] == vec[(n+1)/2-1]){
        countA++;
      }
      else if(vec[i] == vec[(n+1)/2]){
        countB++;  
      }
    }
    if(countA>countB)
      b = vec[(n+1)/2-1];
    else
      b = vec[(n+1)/2];
  }
  else{
    b = vec[(n+1)/2 -1];
  }
  //test(countA);
  //test(countB);
  
  
  rep0(i,n){
    if(vec[i]-b < 0){
      sum += (-1)*(vec[i]-b);
    }
    else{
      sum += vec[i] - b;
    }
  }
  cout << sum << endl;
    
   
  //rep0(i,n)
    //test(vec[i]); 
  
}