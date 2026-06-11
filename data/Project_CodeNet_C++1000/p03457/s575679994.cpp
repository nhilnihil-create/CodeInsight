#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;

int main(void) {
    ll N; cin >> N;
    
    ll t,x,y;
    ll now_x = 0;
    ll now_y = 0;
    ll now_t = 0;
    ll cost = 0;
    ll point = 0;
    string ans = "No";
    for (int i = 0; i < N; i++) {
        cin >> t >> x >> y;
        cost = abs(now_x - x) + abs(now_y - y);
        point = t - now_t;
        if ((point - cost) >= 0 && (point - cost)%2 == 0) {
            ans = "Yes";
        }else{
            ans = "No";
            break;
        }
        now_x = x;
        now_y = y;
        now_t = t;
        
    }
    cout << ans << endl;
    
    return 0;
}
