//include
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath> 
#include <iomanip>
#include <math.h>
#include <utility>
#include <functional>
#include <cstdlib>
//using
using namespace std;
using vl = vector <long long>;
using vs = vector <string>;
using vc = vector <char>;
using ll= long long;
using vvl = vector<vector<ll> >;
//vector<vector<char> > hyou(N, vector<char>(N));
using vd = vector <double>;
//define
//#define int long long
#define rep(i,n) for(int i=0; i<n; i++)
#define print(n) cout<<n<<endl;
#define sortp(d) sort(d.begin(),d.end()) //1234
#define sortm(d) sort(d.rbegin(),d.rend()) //4321
//素数判定　O(√A) 
bool is_prime(int x){
 if(x<=1) return false;
 for(int i=2;i*i<=x;i++)
 if(x%i==0) return false;
 return true;
 }
/*順列生成
do {
  // 順列に対する処理
} while (next_permutation(配列変数.begin(), 配列変数.end()));*/

//絶対値　abs()

//グローバル変数宣言
 ll p=0,q=0,r=0;

int main(){
  string s;
  cin>>s;
  r=753;
  rep(i,s.size()-2){
    p=(s[i]-'0')*100+(s[i+1]-'0')*10+(s[i+2]-'0')*1;
    q=abs(p-753);
    r=min(q,r);
  }
  print(r);
}