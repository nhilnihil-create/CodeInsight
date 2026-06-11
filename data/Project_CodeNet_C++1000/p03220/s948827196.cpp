#include <iostream>
using namespace std;
int main(){
    int n,t,a;
    cin >> n >> t >> a; 
    int tmp = 1e9;
    int ans;
    for(int i = 0; i < n; i++){
        int h; cin >> h;
        if(abs(1000*t - 6*h - 1000*a) < tmp){
            tmp = abs(1000*t - 6*h - 1000*a);
            ans = i+1;
        }
    }
    cout << ans << endl;
    return 0;
}