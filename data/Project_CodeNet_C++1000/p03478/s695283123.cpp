#include <bits/stdc++.h>
using namespace std;
bool isValid(int value, int a, int b){
    int sum = 0;
    while(value>0){
        sum+=value%10;
        value/=10;
    }
    if( (sum>=a) &&
        (sum<=b)){
            return true;
    }else{
        return false;
    }
}
int main(){
    int n,a,b;
    cin >> n >> a >> b;
    long ans = 0;
    for(int i = 1; i <= n; i++){
       if(isValid(i,a,b)){
           ans += (long)i;
       } 
    }
    cout << ans << endl;
    return 0;
}