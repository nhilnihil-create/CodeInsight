#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <utility>
#include <string>
#include <unordered_map>
using namespace std;
long long ans = 10000000000;
int main(void){
    long long N,K;
    cin >> N >> K;
    long long h[N];
    for(int i=0;i<N;i++){
        cin >> h[i];
    }
    sort(h,h+N);
    ans = h[N-1] - h[0];
    for(int i=0;i+K-1<N;i++){
        ans = min(ans,h[i+K-1]-h[i]);
    }
    cout << ans;
}
