#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n, ans = 0;
    cin >> n;
    if(n == 3){
        cout << "2 5 63" << endl;
    }else if(n == 4){
        cout << "2 5 20 63" << endl;
    }else if(n == 5){
        cout << "2 5 20 30 63" << endl;
    }else{
        int t = 0;
        vector<int> ans(n), a = {2, 3, 4, 6};
        for(int i = 0; i < n; i++){
            ans[i] = 6 * (int)(i / 4) + a[i % 4];
            t += ans[i];
            t %= 6;
        }
        if(t == 2){
            ans[4] = 6 * (int)(1 + n / 4);
        }else if(t == 3){
            ans[5] = 6 * (int)(1 + n / 4);
        }else if(t == 5){
            ans[5] = 6 * (int)(n / 4) + 4;
        }
        cout << ans[0];
        for(int i = 1; i < n; i++){
            cout << " " << ans[i];
        }
        cout << endl;
    }
    return 0;
}
