#include <bits/stdc++.h> 
#define rep(i,n) for(int i=0; i<(n); ++i)
#define cout(x) cout<<x<<endl
#define all(v) v.begin(), v.end()
using namespace std;
//型エイリアス
using vi = vector<int>;
using ll = long long;
using P = pair<int,int>;
using Graph = vector<vector<int>>;
const ll inf = 1e18;
const int N = 2e5 + 10;


int main(){
    int d,n;
    cin >> d >> n;

    if(d==0){
        if(n==100) cout(101);
        else cout(n);
    }
    if(d==1){
        if(n==100) cout(10100);
        else cout(100*n);
    }
    if(d==2){
        if(n==100) cout(1010000);
        else cout(10000*n);
    }

    return 0;
}