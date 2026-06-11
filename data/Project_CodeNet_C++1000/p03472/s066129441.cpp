#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using P = pair<int, int>;

int main(){
    int n, h;
    cin >> n >> h;
    vector<P> sword(n);
    for(int i = 0; i < n; i++) cin >> sword[i].second >> sword[i].first;
    sort(sword.begin(), sword.end());

    int amax_i = 0;
    for(int i = 1; i < n; i++){
        if(sword[amax_i].second < sword[i].second) amax_i = i;
    }

    int sum = 0;
    int ans = 0;
    for(int i = n-1; i >= 0; i--){
        if(sum >= h) break;
        if(sword[i].first >= sword[amax_i].second){
            ans++;
            sum += sword[i].first;
        }
    }

    if(sum < h) ans += (h-sum+sword[amax_i].second-1)/sword[amax_i].second;
    cout << ans << endl;
    return 0;
}