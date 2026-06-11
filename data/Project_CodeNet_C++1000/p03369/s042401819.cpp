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

ll sum(int n){
   if(n == 0){
      return n;
   }else{
      return sum(n/10) + n%10;
   }
}
using namespace std;


int main(){
   
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);

   string s; cin >> s;
   int cost = 0;
   for(char i : s){
      if(i != 'x') cost++;
   }
   cout << 700 + cost * 100;
   return 0;
}
