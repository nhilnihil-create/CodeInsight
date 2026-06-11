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


string toString(int n) 
{ 
    string str; 
    stringstream ss; 
    ss << n; 
    ss >> str; 
    return str; 
} 
  
// Method to convert n to base negBase 
string toNegativeBase(int n, int negBase) 
{ 
    //  If n is zero then in any base it will be 0 only 
    if (n == 0) 
        return "0"; 
  
    string converted = ""; 
    while (n != 0) 
    { 
        // Get remainder by negative base, it can be 
        // negative also 
        int remainder = n % negBase; 
        n /= negBase; 
  
        // if remainder is negative, add abs(base) to 
        // it and add 1 to n 
        if (remainder < 0) 
        { 
            remainder += (-negBase); 
            n += 1; 
        } 
  
        // convert remainder to string add into the result 
        converted = toString(remainder) + converted; 
    } 
  
    return converted; 
} 

int main() {


ll n;
cin>>n;



cout<<toNegativeBase(n,-2);
  
  return 0;
}
