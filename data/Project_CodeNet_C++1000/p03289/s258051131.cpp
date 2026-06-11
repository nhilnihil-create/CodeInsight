#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int main(){
    IOS;
    string s;
    cin >> s;
    if(s[0]=='A'){
        int count = 0;
        int capitalC = 0;
        for(int i=2; i<s.size()-1; i++){
            if(s[i]=='C'){
                count++;
                capitalC++;
            }
        }
        if(capitalC==1){
            bool ans = true;
            for(int i=0; i<s.size(); i++){
                if(s[i]!='A' && s[i]!='C'){
                    if(islower(s[i])==false){
                        cout << "WA" <<endl;
                        return 0;
                    }else{
                        ans = false; 
                    }
                }
            }
            if(ans==false){
                cout << "AC" <<endl;
            }
        }else{
            cout <<"WA" <<endl;
        }
    }else{
        cout << "WA" <<endl;
    }
}