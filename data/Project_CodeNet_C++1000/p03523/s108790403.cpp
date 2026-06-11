#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;

    int n = s.length();

    if(n >= 10){
        cout << "NO" << endl;
    }else{
        int poj = -1;
        int cou = 0;
        for(int i = 0; i < n - 3; i++){
            if(s.substr(i, 3) == "KIH"){
                poj = i + 3;
                break;
            }else{
                if(s[i] == 'A'){
                    cou++;
                }else{
                    break;
                }
            }

            if(cou == 2){
                break;
            }
        }

        if(poj != -1){
            cou = 0;
            for(int i = poj; i < n; i++){
                if(s[i] == 'B'){
                    poj = i;
                    break;
                }else if(s[i] == 'A'){
                    cou++;
                }else{
                    poj = -1;
                    break;
                }

                if(cou == 2){
                    poj = -1;
                    break;
                }
            }

            if(poj != -1){
                cou = 0;
                int t = poj;
                for(int i = poj + 1; i < n; i++){
                    if(s[i] == 'R'){
                        poj = i;
                        break;
                    }else if(s[i] == 'A'){
                        cou++;
                    }else{
                        poj = -1;
                        break;
                    }

                    if(cou == 2){
                        poj = -1;
                        break;
                    }
                }

                if(t == poj){
                    poj = -1;
                }

                if(poj != -1){
                    if(poj == n - 2 || poj == n - 1){
                        if(poj == n - 2){
                            if(s[poj + 1] != 'A'){
                                poj = -1;
                            }
                        }
                    }else{
                        poj = -1;
                    }
                }
            }
        }
        if(poj == -1){
            cout << "NO" << endl;
        }else{
            cout << "YES" << endl;
        }
    }
}