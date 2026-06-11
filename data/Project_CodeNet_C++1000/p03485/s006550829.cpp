#include <bits/stdc++.h> //C++の機能を「全て」読み込むための命令
#define rep(i,n) for(int i=0; i<(n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
const ll inf=1e18;
const int N=2e5+10;
ll factorial(ll x){
    if(x==0||x==1) return 1;
    return x*factorial(x-1);
}

int main(){
    int a,b;
    cin >> a >> b;
    //doubelにする強引な方法
    // int x = ((double)a+(double)b)/2.0 + 0.999999999;

    //組み込み関数ceilを使う方法
    int x = ceil(((double)a+(double)b)/2);

    //
    // int x = a+b;
    // if(x%2!=0) x = (x+1)/2;

    cout<<x<<endl;
    return 0;
}