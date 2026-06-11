#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(x) (x).begin(),(x).end()
template <class T> inline bool chmin(T &a, T b) {if (a > b){a = b;return true;}return false;}
template <class T> inline bool chmax(T &a, T b) {if (a < b){a = b;return true;}return false;}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int a,b,c,d;cin>>a>>b>>c>>d;
    string ans="No";
    if(abs(a-c)<=d){
        ans="Yes";
    }
    if(abs(a-b)<=d && abs(b-c)<=d){
        ans="Yes";
    }
    cout<<ans<<endl;
}