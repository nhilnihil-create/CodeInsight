#include <bits/stdc++.h>
using namespace std;
bool isValid(int value){
    bool ret = true;
    vector <int> digit;
    while(value>0){
        digit.push_back(value%10);
        value/=10;
    }
    if(digit.size()<=1){
        ret = true;
    }else{
        for(int i = 0; i < digit.size()/2; i++){
            if(digit[i]!=digit[digit.size()-1-i]){
                ret = false;
                break;
            }
        }
    }
    return ret;
}
int main(){
    int a,b;
    cin >> a >> b;
    int ans = 0;
    for(int i = a; i <= b; i++){
        if(isValid(i))ans++;
    }
    cout << ans << endl;
    return 0;
}