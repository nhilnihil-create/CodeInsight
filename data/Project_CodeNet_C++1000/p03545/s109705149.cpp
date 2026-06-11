#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
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
    char ca,cb,cc,cd;cin>>ca>>cb>>cc>>cd;
    int a=ca-'0', b=cb-'0', c=cc-'0', d=cd-'0';
    vector<vector<int>> v={{b,-b},{c,-c},{d,-d}};
    ll sum;
    REP(i,2){
        REP(j,2){
            REP(k,2){
                sum=a+v[0][i]+v[1][j]+v[2][k];
                if(sum==7){
                    string op1,op2,op3;
                    (i==0)?op1="+":op1="";
                    (j==0)?op2="+":op2="";
                    (k==0)?op3="+":op3="";
                    cout<<a<<op1<<v[0][i]<<op2<<v[1][j]<<op3<<v[2][k]<<"=7"<<endl;
                    return 0;
                }
            }
        }
    }
return 0;
}
