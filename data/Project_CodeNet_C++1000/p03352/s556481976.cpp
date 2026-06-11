#include <bits/stdc++.h>
using namespace std;
bool isValid(int value){
    bool ret = false;
    for(int i = 2; i <= (value/2); i++){
        int tmp = value;
        while(true){
            if(tmp%i==0){
                tmp/=i;
            }else{
                if(tmp==1){
                    ret = true;
                    break;
                }else{
                    break;
                }
            }
        }
    }
    return ret;
}
int main(){
    int x;
    cin >> x;
    int ans = 1;
    for(int i = x; i > 1; i--){
        if(isValid(i)){
            ans = i;
            break;
        }
    }
    cout << ans << endl;
}