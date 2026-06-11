#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<n;i++)
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0;}

int main() {
    int n,k;
    cin >> n>> k;
    vector<int>a(n);
    rep(i,n) cin >> a[i];
    int res = 0;
    int right = 0;
    while(true) {
        if(res==0){
            res++;
            right += k;
        } else {
            res++;
            right += k-1;
        }
        if(right>=n) break;
    }
    cout << res << endl;
}
