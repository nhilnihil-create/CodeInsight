//include
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath> 
#include <iomanip>
#include <math.h>
#include <utility>
//using
using namespace std;
/*using vi = vector<int>;
using vs = vector<string>;
using vc = vector<char>;*/
//define
#define int long long
#define rep(i,n) for(int i=0; i<n; i++)
#define print(n) cout<<n<<endl;
//グローバル変数宣言
int a=0,b=0,c=0,d=0,n=0;

//int sa(int n,int p){if(n>=p)return n-p;else return p-n;}

signed main(){
    cin>>a>>b>>c;
    vector<vector<int> > x(a, vector<int>(b));
    vector<int>y(b);
    rep(i,b)cin>>y[i];
    rep(i,a)rep(j,b)cin>>x.at(i).at(j);
    rep(i,a)
    {
        d=c;
        rep(j,b)d+=x[i][j]*y[j];
        if(d>0)n++;
    }
    print(n);
}