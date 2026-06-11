#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll,ll> l_l;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
const int INF=1001001000;
const int mINF=-1001001000;
const ll LINF=1010010010010010000;
template<class T> inline bool chmin(T& a, T b) {
if (a > b) {
a = b;
return true;
}
return false;
}
template<class T> inline bool chmax(T& a, T b) {
if (a < b) {
a = b;
return true;
}
return false;
}
int main(){
    string s;cin >> s;
    int n=s.size();
    int up,down;
    if(n%2==0){
        up=n/2;
        down=up-1;
    }
    else{
        up=n/2;
        down=n/2;
    }
    int chara=s[up];
    while(s[up]==chara&&s[down]==chara){
        up++;
        down--;
        if(down<0) break;
    }
    cout << up << endl;
    return 0;
}