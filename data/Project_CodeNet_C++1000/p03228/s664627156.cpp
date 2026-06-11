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
    int a,b;cin>>a>>b;
    int k;cin>>k;
    rep(i, k){
        if(i%2==0){
            if(a%2!=0){
                a-=1;
            }
            a/=2;
            b+=a;
        } else {
            if(b%2!=0){
                b-=1;
            }
            b/=2;
            a+=b;
        }
    }
    cout<<a<<" "<<b<<endl;
}