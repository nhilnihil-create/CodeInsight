#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
  ll n,a,b;
  cin >> n >> a >> b;
  
  int p1=0,p2=0,p3=0; //各区画ごとの該当配点問題の個数
  rep(i,n){
    int tmp = 0; cin >> tmp;
    if(tmp<=a) p1++;
    else if(a<tmp && tmp<=b) p2++;
    else p3++;
  }
  cout << min(p1,min(p2,p3)) << endl;
}