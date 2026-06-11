#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
const int mod = 1e9+7;
const int mx = INT_MAX;
const long double pi = 4*atan((long double)1);
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vii;
#define file "orz"
#include <bits/stdc++.h>
using namespace std;
ll calc(ll n) 
{   
  
    switch(n & 3)
    { 
    case 0: return n;   
    case 1: return 1;   
    case 2: return n + 1;    
    case 3: return 0;    
    } 
} 

int main()
{
    ll a,b;
    cin>>a>>b;
    a = calc(a-1);
    b = calc(b)^a;
    cout<<b;	
//    cout<<x;
}
