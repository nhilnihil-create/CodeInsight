#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define REP(i, n) for (int i = 0; i < (n); i++)

const long double EPS = 1e-10;
const long long INF = 1e18;
const long double PI = acos(-1.0L);


ll gcd(ll a, ll b){  if(b==0){  return a; }   return gcd(b , a%b); }


void solve(int a[],int n){
  int flag = 0;
  for(int i=0;i<n-1;i++){
    if(a[i+1]-a[i] > 1 ){
      cout<<"NO\n";
      flag = 1;
      break;
    }
  }

  if(!flag){
    cout<<"YES\n";
  }
  
}

ll min(ll a , ll b){   if (a > b){    return b; }  return a; }



 int base_10(int num){
 
  vector<int> vect;
  vect.clear();
  while(num!=0){

    vect.push_back(num%10);
    num /= 10;

  }

  
   int number = 0;
   for(int i=vect.size()-1;i>=0;i--){
     number  = number*10 + vect[i];
   }


   return number;
 }

 int check(int num){
  vector<int> vect;

    while(num!=0){
      vect.push_back(num%10);
      num /= 10;
    }

    for(int i=0;i<vect.size()-1;i++){
       if(vect[i]!=vect[i+1])
          return 0;
    }

    return 1;


 }

int main(){
  int n;
  cin>>n;
  int flag = 0;
  
  while(1 && !flag){


   if(check(n)){
     cout<<n<<"\n";
     flag = 1;
     break;
   }
   n++;

   if(flag){
     break;
   }

  }



  return 0;
}


