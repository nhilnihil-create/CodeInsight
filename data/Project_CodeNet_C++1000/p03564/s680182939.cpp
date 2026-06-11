#include<iostream>
#include<cmath>

using namespace std;

int main(){
    int n, k;
    int ans = 0, r = 0;
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        if(pow(2,i) > k){
            ans += k;
            r++;
        }
    }
    cout << ans + pow(2,n-r) << endl;
}