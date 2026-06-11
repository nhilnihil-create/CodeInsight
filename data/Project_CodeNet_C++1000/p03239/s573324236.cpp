#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n, T;
    cin >> n >> T;
    vector<int> c(n), t(n);
    for (int i=0; i<n; i++){
        cin >> c[i] >> t[i];
    }

    int ans = 10000;
    for (int i=0; i<n; i++){
        if(t[i] <= T){
            ans = min(ans, c[i]);
        }
    }

    if(ans > 1000){
        cout << "TLE" << endl;
    }else{
        cout << ans << endl;
    }

    return 0;
}