#include <bits/stdc++.h>
using namespace std;
bool Check(int num){
    
    string s = to_string(num);
    int len = s.size();
    for(int i=0;i<(len/2);i++){
        if(s[i] != s[len-i-1]) return false;
    }
    
    return true;
}
int main(void){
    
    int A,B,ans=0;
    cin >> A >> B;
 
    for(int i=A;i<=B;i++) if(Check(i)) ans++;
    cout << ans << endl;
}