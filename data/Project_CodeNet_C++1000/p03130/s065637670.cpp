#include <bits/stdc++.h>
using namespace std; 
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define ALL(a) (a).begin(),(a).end()
#define ll long long
long long min(long long x,long long y){return (x<y ? x:y);}
long long max(long long x,long long y){return (x>y ? x:y);}
#define ld long double
int stoi(string s) {return atoi(s.c_str());}
int keta(ll x){ if(x<10){return 1;} else{return keta(x/10) + 1;}}
#define LINEY "YES\n"
#define Liney "Yes\n"
#define LINEN "NO\n"
#define Linen "No\n"

//1---2---3---4

int main(){
  int num_e[4];  REP(i,4){num_e[i]=0;}
  int a,b;
  REP(i,3){
    cin >> a>>b;
    num_e[a-1]++;
    num_e[b-1]++;
  }
  bool r = true;
  REP(i,4){
    if(num_e[i]>2){r =false;break;}
  }
  cout << (r?LINEY:LINEN);
  
}