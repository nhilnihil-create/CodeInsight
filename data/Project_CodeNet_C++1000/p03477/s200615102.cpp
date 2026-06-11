#include <bits/stdc++.h>

#define ll long long
#define mk make_pair
#define pb push_back
#define ff first
#define sc second
#define all(x) x.begin(), x.end();

ll gcd(ll a, ll b){
   if(b == 0) return a;
   
   return gcd(b, a % b);
}

using namespace std;


int main(){
   
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);

   int a,b,c,d;cin>>a>>b>>c>>d;
   if(a+b > c+d){
      cout << "Left";
   }else if(a+b < c+d){
      cout << "Right";
   }else{
      cout << "Balanced";
   }
   return 0;
}
