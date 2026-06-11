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
//using
using namespace std;
/*using vi = vector <int>;
using vs = vector <string>;
using vc = vector <char>;*/
//vector<vector<char> > hyou(N, vector<char>(N));
//define
#define int long long
#define rep(i,n) for(int i=0; i<n; i++)
#define print(n) cout<<n<<endl;
//グローバル変数宣言
int a=0,b=0,c=0,d=0,n;

signed main(){
    cin>>n;
    vector<int>A(n);
    rep(i,n)cin>>A[i];
    sort(A.rbegin(),A.rend());
    rep(i,n){
        if(i%2==0){
            a+=A[i];
        }else b+=A[i];
    }
    cout<<a-b<<endl;
}
