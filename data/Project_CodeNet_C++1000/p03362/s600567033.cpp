#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(x) (x).begin(),(x).end()
template <class T> inline bool chmin(T &a, T b) {if (a > b){a = b;return true;}return false;}
template <class T> inline bool chmax(T &a, T b) {if (a < b){a = b;return true;}return false;}

bool isPrime(int x){
    int i;
    if(x < 2)return 0;
    else if(x == 2) return 1;
    if(x%2 == 0) return 0;
    for(i = 3; i*i <= x; i += 2) if(x%i == 0) return 0;
    return 1;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; cin>>n;
    int cnt = 0;
    for(int i=1; i<= 55555; i++){
        if(isPrime(i) && i%5==1){
            cout<<i<<" ";
            cnt++;
        } 
        if(cnt==n) break;
    }
    cout<<endl;
    return 0;
}
// abc096_d