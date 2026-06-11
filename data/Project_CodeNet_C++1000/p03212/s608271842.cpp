#include <iostream>
using namespace std;
bool is753(int N){
    bool a7 = 0;
    bool a5 = 0;
    bool a3 = 0;
    while(N){
        int a = N % 10;
        if(a==7){
            a7 = 1;
        }else if(a==5){
            a5 = 1;
        }else if(a==3){
            a3 = 1;
        }else{
            return 0;
        }
        N /= 10;
    }
    if(a7 && a5 && a3) return 1;
    return 0;
}

int main(){
    int n;
    cin >> n;
    int ans = 0;
    if(n<500000000){
        for(int i=1; i<=n; i++){
            ans += is753(i);
        }
    }else{
        ans += 14384;
        for(int i=500000000; i<=n; i++){
            ans += is753(i);
        }
    }
    cout << ans << endl;
    return 0;
}