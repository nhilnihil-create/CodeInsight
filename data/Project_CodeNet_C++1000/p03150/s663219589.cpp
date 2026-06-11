#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;

    int n = s.length();
    int flag = 0;
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            string t = s;
            string k = t.erase(i, j - i);
            if(k == "keyence"){
                flag = 1;
                break;
            }
        }

        if(flag == 1){
            break;
        }
    }

    if(flag == 1){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
}