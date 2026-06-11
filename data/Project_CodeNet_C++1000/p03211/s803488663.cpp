#include <iostream>
using namespace std;
int main(void){
    int ans=1000;
    string s;
    cin >> s;
    for(int i=2;i<s.size();i++){
        int tmp=(s[i-2]-'0')*100+(s[i-1]-'0')*10+s[i]-'0';
        if(ans>abs(tmp-753)) ans = abs(tmp-753);
    }
    cout << ans;
}