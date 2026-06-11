#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define p pair<int,int>
template<class T> void chmax(T& a, T b){if(a < b) a = b;}
template<class T> void chmin(T& a, T b){if(a > b) a = b;}
int N, H ,W, ans;
int main(){
    cin >> N >> H >> W;
    for(int i = 0; i < N; i++){
        int A, B;
        cin >> A >> B;
        if(A >= H && B >= W) ans++;
    }
    cout << ans << endl;
    return 0;
}