//include
//------------------------------------------
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <bits/stdc++.h>

using namespace std;
 
//conversion
//------------------------------------------
inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}
 
//math
//-------------------------------------------
template<class T> inline T sqr(T x) {return x*x;}
 template<class T>bool chmin(T &a, const T &b) { if (b<a) { a = b; return 1; } return 0; }
//typedef
//------------------------------------------
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef long long LL;
 
//container util
//------------------------------------------
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())
 
//repetition
//------------------------------------------
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define fore(i,a) for(auto &i:a)

//constant
//--------------------------------------------
const double EPS = 1e-10;
const double PI  = acos(-1.0);
 
//clear memory
#define CLR(a) memset((a), 0 ,sizeof(a))
 
//debug
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;
 

LL gcd(LL a, LL b){
    if(b == 0) return a;
    return gcd(b,a%b);
}

LL lcm(LL a, LL b){
    LL g = gcd(a,b);
    return a/g *b;
}


int main(){
    LL a,b,r,x;
    cin >> a >> b;
    string S,T;
    cin >> S >> T;
    LL tmp=0;
    x=a*b;
    LL N=a,M=b;
    if(a<b){
    tmp = a;
    a = b;
    b = tmp;
  }
     r = a % b;
  while(r!=0){
    a = b;
    b = r;
    r = a % b;
  }
    LL y=x/b;
    LL res_S[N];
    LL res_T[M];
    for(int i=0;i<N;++i){
        res_S[i]=i*y/N;
    }
    
    for(int i=0;i<M;++i){
        res_T[i]=i*y/M;
    }
    LL react=0;
    LL pos=0;
    bool exist=true;
    LL n=N/y,m=M/y;
    map<LL,char>res1,res2;
    REP(i,N){
        LL pos = i*(y/N);
        res1[pos]=S[i];
    }
    
    REP(i,M){
        LL pos = i*(y/M);
        res2[pos]=T[i];
    }
    for(LL i = 0; i < y; i+=lcm(y/N,y/M)){
        if(res1[i]!='\0' && res2[i]!= '\0' && res1[i]!=res2[i]){
            cout << -1 << endl;
            return 0;
        }
    }
    cout << y << endl;
    return 0;
}