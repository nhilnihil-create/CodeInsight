#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
struct __INIT{__INIT(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);}} __init;
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define MOD 1000000007
#define INF (1<<30)
#define LINF (lint)(1LL<<56)
#define endl "\n"
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define reprev(i,n) for(int (i)=(n-1);(i)>=0;(i)--)
#define Flag(x) (1<<(x))
#define Flagcount(x) __builtin_popcount(x)
#define pint pair<int,int>
#define pdouble pair<double,double>
#define plint pair<lint,lint>
typedef unsigned long long int ull;
typedef long long lint;

int main(void){
  int N;
  cin >> N;
  if(N >= 8){
    int base = 0;
    for(int i = 0; i < N / 8; i++){
      base = i * 12;
      cout << base + 2 << " " << base + 3 << " " << base + 4 << " " << base + 6 << " " << base + 8 << " " << base + 9 << " " << base + 10 << " " << base + 12 << " ";
    }
    base += 12;
    if(N % 8 == 1)cout << base + 6 << " ";
    else if(N % 8 == 2)cout << base + 2 << " " << base + 4 << " ";
    else if(N % 8 == 3)cout << base + 2 << " " << base + 4 << " " << base + 6 << " ";
    else if(N % 8 == 4)cout << base + 2 << " " << base + 4 << " " << base + 6 << " " << base + 12 << " ";
    else if(N % 8 == 5)cout << base + 3 << " " << base + 4 << " " << base + 8 << " " << base + 9 << " " << base + 12 << " ";
    else if(N % 8 == 6)cout << base + 2 << " " << base + 4 << " " << base + 6 << " " << base + 8 << " " << base + 10 << " " << base + 12 << " ";
    else if(N % 8 == 7)cout << base + 2 << " " << base + 3 << " " << base + 4 << " " << base + 8 << " " << base + 9 << " " << base + 10 << " " << base + 12 << endl;
    cout << endl;
  }else {
    if(N == 3)cout << 2 << " " << 5 << " " << 63 << endl;
    else if(N == 4)cout << "2 5 20 63" << endl;
    else if(N == 5)cout << "14 15 16 18 21" << endl;
    else if(N == 6)cout << "14 15 16 18 21 24" << endl;
    else if(N == 7)cout << "14 15 16 18 21 24 30" << endl;
  }
  return 0;
}