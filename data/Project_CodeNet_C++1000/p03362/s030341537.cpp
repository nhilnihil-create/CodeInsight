#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define call(var) cout<<#var<<"="<<var<<endl;
#define dup(x,y) (((x)+(y)-1)/(y))
using ll=long long;
using vi = vector<int>;
using vl = vector<ll>;
using vb = vector<bool>;
using Graph = vector<vi>;
using P = pair<int,int>;
const int MOD=(int)1e9+7;
const int INF=(int)1e9;
const ll LINF=(ll)1e18;
const int INTMAX = 2147483647;
template<class t,class u> inline bool chmax(t&a,u b){if(a<b){a=b;return true;}return false;}
template<class t,class u> inline bool chmin(t&a,u b){if(b<a){a=b;return true;}return false;}

int main(){
    int n;cin >> n;
    vector<int> pr;
    vb a(55556);
    for(int i=2;i<55556;++i){
        if(a[i]) continue;
        pr.push_back(i);
        for(int j=i;j<55556;j += i) a[j] = 1;
    }
    //call("why");
    int cur = 1;
    reverse(pr.begin(), pr.end());
    while(cur <= n){
        if(pr.back() % 10 == 1){
            cout << pr.back() << " ";
            ++cur;
        }
        pr.pop_back();
    }
}