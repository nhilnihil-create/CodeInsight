#include <bits/stdc++.h>
using namespace std;

int n;

int num[4];

const int maxn = 3e4 + 5;
bool vis[maxn];


int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    if(n >= 6){
        num[0] = 2, num[1] = 3, num[2] = 4, num[3] = 6;
        long long sum = 0;
        for(int i = 0;i < n;i++){
            sum += num[i % 4]; 
            vis[num[i % 4]] = 1;
            num[i % 4] += 6;
        }
        if(sum % 6 == 0){

        }else if(sum % 6 == 2){
            vis[8] = false;
            vis[num[3]] = true;
        }else if(sum % 6 == 3){
            vis[9] = false;
            vis[num[3]] = true;
        }else if(sum % 6 == 5){
            vis[9] = false;
            vis[num[2]] = true;
        }
        vector<int> ans;
        for(int i = 1;i <= 30000;i++){
            if(vis[i]){
                ans.push_back(i);
            }
        }
        for(int i = 0;i < n;i++){
            cout << ans[i];
            if(i == n - 1){
                cout << endl;
            }else{
                cout << " ";
            }
        }
    }else if(n == 3){
        cout << 2 << " " << 5 << " " << 63 << endl;
    }else if(n == 4){
        cout << 2 << " " << 5 << " " << 20 << " " << 63 << endl;
    }else if(n == 5){
        cout << 2 << " " << 5 << " " << 20 << " " << 63 << " " << 90 << endl;
    }
    return 0;
}
