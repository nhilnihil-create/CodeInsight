#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <stack>
using namespace std;
using ll = long long int;

int main(){
    int n; cin >> n;
    vector<int> d(n);
    int ans = 0;
    for(auto& v:d){
        cin >> v;
    }
    if(n > 23){
        cout << "0" << endl;
        return 0;
    }
    else if(n > 11){
        vector<int> cnt(13, 0);
        for(auto& v:d){
            cnt[v]++;
        }
        for(int i=1; i<12; i++){
            if(cnt[i] > 2){
                cout << "0" << endl;
                return 0;
            }
        }
        if(cnt[0] > 0 || cnt[12] > 1){
            cout << "0" << endl;
            return 0;
        }
        cout << "1" << endl;
        return 0;
    }
    else{
        for(ll i=0; i<(1L << n); i++){
            vector<int> time(n+2, 0);
            time[n] = 0; time[n+1] = 24;
            for(int j=0; j<n; j++){
                if(i & (1L << j)){
                    time[j] = d[j];
                }
                else{
                    time[j] = 24 - d[j];
                }
            }
            sort(time.begin(), time.end());
            int val = 24;
            for(int j=0; j<n+1; j++){
                val = min(val, time[j+1] - time[j]);
            }
            ans = max(ans, val);
        }
    }
    cout << ans << endl;
    return 0;
}