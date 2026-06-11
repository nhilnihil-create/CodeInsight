#include<bits/stdc++.h>
using namespace std;

int main(){
    int a, b;
    string s;
    cin >> a >> b;
    cin >> s;
    bool flg=true;
    for(int i=0; i<(a+b+1); i++){
        if(i==a){
            if(s.at(i) == '-')
                flg = true;
            else{
                flg = false;  break;
            }
        }else{
            if(s.at(i)>='0' && s.at(i)<='9')
                flg = true;
            else{
                flg = false; break;
            }
        }
    }
    if(flg) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}