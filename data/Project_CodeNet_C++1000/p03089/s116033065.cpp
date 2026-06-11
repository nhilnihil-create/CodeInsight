#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define rep(i, n) for(i = 0; i < n; i++)

int main(){
    int i, N;
    cin >> N;
    vector<int> bs(N);
    rep(i, N){
        cin >> bs[i];
        bs[i]--;
    }


    bool success;
    vector<int> ans(N);
    for(int end = N - 1; end >= 0; end--){
        success = false;
        for(int ind = end; ind >= 0; ind--){
            if(bs[ind] == ind){
                success = true;
                ans[end] = ind+1;
                bs.erase(bs.begin() + ind);
                break;
            }
        }
        if(!success){
            break;
        }
    }

    if(success){
        rep(i, N){
            cout << ans[i] << '\n';
        }
    }
    else{
        cout << -1 << endl;
    }

    
    return 0;
}