#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    string com="keyence";
    string ans="YES";
    if(s==com){
        cout << ans << endl;
        return 0;
    }
    int a=s.size();
    for(int i=0;i<a;i++){
        for(int j=i;j<a;j++){
            string str="";
            for(int k=0;k<a;k++){
                if(k>=i&&k<=j){
                    continue;
                }
                else{
                    str.push_back(s[k]);
                }
            }
            if(str==com){
                cout << ans << endl;
                return 0;
            }
        }
    }
    cout << "NO" << endl;
    return 0;
}