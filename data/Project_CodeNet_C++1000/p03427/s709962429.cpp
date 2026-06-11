#include<bits/stdc++.h>
using namespace std;

int main(){
    string n; cin >> n;
    int res = 0;
    bool flg_1 = true;
    bool flg = true;
    if(n.at(0)!='9') flg_1 = false; 
    for(int i=1; i<n.length(); i++){
        if(n.at(i) != '9'){
            flg = false; break;
        }    
    }
    if(n.length() == 1){
        res = n.at(0) - '0';
    }else{
        if(flg && flg_1){
            res = 9*n.length();
        }else if(flg && !flg_1){
            res = (n.at(0) - '0') + 9*(n.length()-1);
        }else{
            res = (n.at(0) - '0')-1 + 9*(n.length()-1);
        }
    }
    
    cout << res << endl;

    return 0;
}