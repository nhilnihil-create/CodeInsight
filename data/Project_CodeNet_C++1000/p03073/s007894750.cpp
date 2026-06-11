#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string> 
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(x) (x).begin(),(x).end() //sortなどの引数を省略したい
#define SIZE(x) ((ll)(x).size()) //sizeをsize_tからllに直しておく
#define MAX(x) *max_element(ALL(x)) //最大値を求める
#define MIN(x) *min_element(ALL(x)) //最小値を求める
typedef long long ll;
typedef long double ld;
int main(){
     string s;
     cin>>s;
     ll n=SIZE(s);
     string a,b;
     REP(i,n){
         if(i%2==0){
             a+="0";
             b+="1";
         }else{
             a+="1";
             b+="0";
         }
     }
     ll a_cost=0, b_cost=0;
     REP(i,n){
         char s_num=s[i], a_num=a[i], b_num=b[i];
         if(s_num!=a_num){
             a_cost++;
         }else{
             b_cost++;
         }
     }
     cout<< min(a_cost, b_cost);
     
    return 0;
}
