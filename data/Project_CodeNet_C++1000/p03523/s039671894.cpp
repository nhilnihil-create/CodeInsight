#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <cassert>
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define srep(i,n,m) for(int i=n;i<m;i++)
#define elif else if
#define INF 1000000007
#define pi 3.141592653589793
using namespace std;
int saidaikouyakusuu(int a,int b){
    if(b==0) return a;
    return saidaikouyakusuu(b,a%b);
}
int saisyoukoubaisuu(int a,int b){
    return a*b/saidaikouyakusuu(a,b);
}
int n,m,cnt=0,aa[220000],o,p;
pair<int,int> pp[220000];
string s,sa,ss[220000];
char c,ca;
double d=0.0;
queue<int> que;
signed main(){
    cin>>s;
    rep(i,16){
        sa="";
        if(i%2==0){
            sa+="AKIH";
        }else{
            sa+="KIH";
        }
        if(i/2%2==0){
            sa+="AB";
        }else{
            sa+="B";
        }
        if(i/4%2==0){
            sa+="AR";
        }else{
            sa+="R";
        }
        if(i/8%2==0){
            sa+="A";
        }
        if(s==sa){
            cout<<"YES"<<endl;
            return 0;
        }
    }
    cout<<"NO"<<endl;
}