#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
using namespace std;

constexpr int max_t = 300000;

int main(){
    int n; cin >> n;
    int c; cin >> c;
    vector<int> v[32];
    for(int i=0;i<32;i++) v[i].assign(max_t+20,0);

    for(int i=0;i<n;i++){
        int s,t; cin >> s >> t;
        int x; cin >> x;
        x--;

        v[x][2*s]++;
        v[x][2*t]--;
    }
    for(int i=0;i<max_t;i++){
        for(int j=0;j<32;j++) v[j][i+1] += v[j][i];
    }

    vector<int> v2(max_t+20,0);
    for(int i=0;i<max_t;i++){
        for(int j=0;j<32;j++){
            if(v[j][i] > 0 || v[j][i+1] > 0){
                v2[i] |= (1<<j);
            }
        }
    }

    //for(int i=0;i<20;i++){
    //    cout << bitset<4>(v2[i]) << " ";
    //}
    //cout << endl;

    int ans = 0;
    for(int i=0;i<max_t;i++){
        int cnt = 0;
        for(int bit = 0; bit < 32;bit++){
            if(v2[i] & (1<<bit)) cnt++;
        }
        ans = max(ans,cnt);
    }
    cout << ans << endl;
}
