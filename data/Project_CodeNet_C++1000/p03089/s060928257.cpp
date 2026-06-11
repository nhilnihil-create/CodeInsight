#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> b;
    int ans[n];
    for(int i = 0; i < n; i++){
        int k = 0;
        cin >> k;
        k--;
        b.push_back(k);
        ans[i] = 0;
    }

    int flag = 0;
    int now = n;
    for(int i = n - 1; i >= 0; i--){
        flag = -1;
        for(int j = 0; j < now; j++){
            if(j == b[j]){
                flag = j;
            }
        }

        if(flag == -1){
            break;
        }else{
            ans[i] = flag;
            b.erase(b.begin() + flag);
        }
        now--;
    }

    if(flag == -1){
        cout << -1 << endl;
    }else{
        for(int i = 0; i < n; i++){
            cout << ans[i] + 1 << endl;
        }
    }
}