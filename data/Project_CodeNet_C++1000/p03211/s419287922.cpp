#include <bits/stdc++.h>
using namespace std;

int main(){
    string s,t;
    cin >> s;
    int num=0;
    int ans=999;
    
    for(int i=0; i<s.size()-2; i++){
        num=100*(s.at(i)-'0')+10*(s.at(i+1)-'0')+(s.at(i+2)-'0');
        ans=min(ans,abs(753-num));
        num=0;
    }
 
    cout << ans << endl;
}