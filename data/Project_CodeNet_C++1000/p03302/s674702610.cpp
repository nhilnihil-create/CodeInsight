#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <numeric>
#include <string>
using namespace std;
const double PI = acos(-1.0);
const string alp = "abcdefghijklmnopqrstuvwxyz";
const string ALP = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const int INTMAX = 2147483647;
const int INTMIN = -2147483648;
const unsigned int UINTMAX = 4294967295;
const long LONGMAX = 9223372036854775807;
const long LONGMIN = -9223372036854775808;
const unsigned long ULONGMAX = 18446744073709551615;
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define REP1(i,n) FOR(i,1,n+1)
#define SUM(c) accumulate((c).begin(),(c).end(),0)
#define UNIQ(c) (c).erase(unique((c).begin(), (c).end()), (c).end());
#define Yn(b) puts(b?"Yes":"No")
#define YN(b) puts(b?"YES":"NO")

bool isprime(int p) {
  if (p==1) return false;
  FOR(i,2,p) {
    if (p%i==0) return false;
  }
  return true;
}

int dig(int n, int a) {return n/(int)pow(10,a)%10;}
int digl(long n, int a) {return n/(long)pow(10,a)%10;}
int digsum(int n) {int r=0;REP(i,10){r+=dig(n,i);}return r;}
int digsuml(long n) {int r=0;REP(i,19){r+=digl(n,i);}return r;}
int dignum(int n) {return n?to_string(n).length():0;}
int dignuml(long n) {return n?to_string(n).length():0;}

int main(){
  int a,b;
  cin >> a >> b;
  if(a+b==15){
    cout << "+";
  } else if (a*b==15){
    cout << "*";
  } else {
    cout << "x";
  }
}