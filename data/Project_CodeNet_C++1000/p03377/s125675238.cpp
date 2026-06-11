#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <limits>
#include <ctype.h> 
#include <stdio.h> 
#include <set> 
#include <iomanip>
#include <vector>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define L(ID) ((ID*2)+1)
#define R(ID) ((ID*2)+2)
#define M(L,R) ((L+R)/2)
#define forr(start,end) for(int i = start; i < end; i++)
#define gap ' '

const int MAXN = 4*1e5;

//ll a[MAXN], ST[MAXN * 4], LZ[MAXN*4];

/*bool perfectSquare(ll x){
    ll s = sqrt(x);
    if(s *s == x) return true;
    else return false;
}*/
typedef long double ld;

ll a[MAXN], n = 0;


ll gcd(ll a, ll b) 
{ 
    if (a == 0) 
        return b; 
    return gcd(b % a, a); 
}


int main() { 
    int a = 0, b = 0, x = 0;
    cin >> a >> b >> x;
    if(a > x){
        cout << "NO" << endl;
        return 0;
    }
    a+=b;
    if(x <= a){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
    

    return 0; 
} 
