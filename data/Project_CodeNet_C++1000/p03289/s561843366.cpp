#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin >> s;
    int posA = -1;
    int posC = -1;
    for(int i = 0; i < s.length(); i++){
        if(isupper(s[i])){
           if((s[i]!='A')&&(s[i]!='C')){
               cout << "WA" << endl;
               return 0;
           }
            if(s[i]=='A'){
                if(posA==-1){
                    posA=i;
                }else{
                    cout << "WA" << endl;
                    return 0;
                }
            }
            if(s[i]=='C'){
                if(posC==-1){
                    posC=i;
                }else{
                    cout << "WA" << endl;
                    return 0;
                }
            }
        }
    }
    if(posA!=0){
        cout << "WA" << endl;
        return 0;
    }
    if((posC>=2)&&(posC<=s.length()-2)){
        cout << "AC" << endl;
        return 0;
    }
    cout << "WA" << endl;
    return 0;
}