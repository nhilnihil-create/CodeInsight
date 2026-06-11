#include "bits/stdc++.h"
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll =long long;
using P =pair<int,int>;

int main(){
    int h,h2,w,w2;
    cin >> h >> w;
    cin >> h2 >> w2;
    int ans;
    ans=h*w-h2*w-h*w2+h2*w2;
    cout << ans << endl;
    

    return 0;
}