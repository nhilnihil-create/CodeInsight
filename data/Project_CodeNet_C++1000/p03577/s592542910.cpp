#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    if(s.size()>=8){
        if(s.substr(s.size()-8)=="FESTIVAL")s=s.substr(0,s.size()-8);
    }
    
    cout << s << endl;
    return 0;
}