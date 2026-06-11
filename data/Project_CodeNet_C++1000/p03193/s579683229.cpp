#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <utility>
#include <string>
using namespace std;
long long ans = 0;
int main(void){
    long long N,H,W;
    cin >> N >> H >> W;
    for(long long i=0;i<N;i++){
        long long h,w;
        cin >> h >> w;
        if(H <= h && W <= w)ans++;
    }
    cout << ans;
}
