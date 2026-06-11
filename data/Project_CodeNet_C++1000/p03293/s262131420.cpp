#include <bits/stdc++.h>
using namespace std;

int main(){
    string s,t;
    cin >> s >> t;
    char tmp;
    string ans="No";

    for(int i=0; i<s.size(); i++){
        if(s==t){
            ans="Yes";
            break;
        }
        else{
            tmp=s.at(0);
            for(int j=0; j<s.size()-1; j++){
                s.at(j)=s.at(j+1);
            }
            s.at(s.size()-1)=tmp;
        }
    }
    cout << ans << endl;
}