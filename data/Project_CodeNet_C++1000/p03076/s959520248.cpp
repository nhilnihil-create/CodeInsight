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
    vector<int> x(5);
    int y = 0,z = 1e9,end = 0;
    rep(i,5){
        cin >> x[i];
        y = x[i]%10;
        if(y!=0 && z>y){
            z = y;
            end = i;
        }
    }

    int sum = 0;
    rep(i,5){
        if(i==end || x[i]%10==0) sum += x[i];
        else{
            sum += x[i] + (10 - x[i]%10);
        }
    }
    cout(sum);

    

    return 0;
}