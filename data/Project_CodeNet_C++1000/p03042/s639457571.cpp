#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int n;
    cin >> n;
    int valid = 0;
    string ans = "NA";
    
    if(n%100 <= 12 && n%100>0){
        ans = "YYMM";
        valid += 1;
    }
    
    if(n/100 <= 12 && n/100 > 0){
        ans = "MMYY";
        valid += 1;
    }
    
    if(valid == 2){
        cout << "AMBIGUOUS" << endl;
    }else{
        cout << ans << endl;
    }
}