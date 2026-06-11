#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    int k;
    cin >> s >> k;
    int ans;
    int i=0;

    while(1){
        if(s.at(i)!='1'){
            cout << s.at(i) << endl;
            break;
        }
        else{
            i++;
            if(k==i){
                cout << 1 << endl;
                break;
            }
        }
    }
}