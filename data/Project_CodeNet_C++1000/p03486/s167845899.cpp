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
    string s;
    string t;
    cin >> s >> t;
    //sは辞書順，tは逆辞書順に並べる．
    sort(s.begin(),s.end());
    sort(t.begin(),t.end());
    reverse(t.begin(),t.end());

    bool can = true;
    can = (s<t);

    if(can) cout<<"Yes"<<endl;
    else  cout << "No" <<endl;
    return 0;
}