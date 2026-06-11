#include <iostream>
#include <algorithm>
using namespace std;

int mny[200010];

int main(void){
    int H, W, N;
    cin >> H >> W >> N;
    for(int i=1; i<=H; ++i) mny[i]=W+1;
    for(int i=0; i<N; ++i){
        int X, Y;
        cin >> X >> Y;
        mny[X]=min(mny[X], Y);
    }
    int ans=1, now=1;
    while(ans<H){
        if(mny[ans+1]<=now) break;
        if(mny[ans+1]>now+1) ++now;
        ++ans;
    }
    cout << ans << endl;
    return 0;
}
