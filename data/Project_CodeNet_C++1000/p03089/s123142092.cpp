#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;

typedef long long ll;
#define rep(i, n) for(int i = 0; i < n; i++)

int main(){
    int N;
    cin >> N;
    vector<int> b(N);
    vector<int> t(N);
    rep(i, N) cin >> b[i];
    rep(i, N) t[i] = (i+1);
    bool is = true;
    rep(i, N){
        if(b[i] > t[i]){
            is = false;
            break;
        }
    }
    if(!is){
        cout << -1 << endl;
        return 0;
    }
    vector<int> ans(N);
    rep(i, N){
        int len = N - i;
        vector<int> a(len);
        rep(j, len) a[j] = (j+1);
        for(int j = len-1; j >= 0; j--){
            if(a[j] == b[j]){
                ans.push_back(a[j]);
                b.erase(b.begin() + j);
                break;
            }
        }
    }
    reverse(ans.begin(), ans.end());
    rep(i, N){
        cout << ans[i] << endl;
    }
    return 0;
}