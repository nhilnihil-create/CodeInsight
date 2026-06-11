#include <bits/stdc++.h>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    string S;
    cin >> S;

    int ans = 10000; 


    for(int i=0; i+2<S.size(); i++){
        int a = S[i] - '0';
        int b = S[i+1] -'0';
        int c = S[i+2] -'0';
        int val = a*100 + b*10 +c;
        if(ans > abs(val-753)){
            ans = abs(val-753);
        }
        
    }

    cout << ans << endl;
    return 0;
    
}