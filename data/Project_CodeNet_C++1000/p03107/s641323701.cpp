#include<bits/stdc++.h>
using namespace std;
int main(){
    
    string s;
    cin >> s;

    int z = 0;
    int o = 0;
    for(int i=0;i<s.length();i++){
        if(s[i]=='0')z++;
        else o++;
    }    
    cout << s.length()-abs(z-o)<<endl;
    
        
    
}