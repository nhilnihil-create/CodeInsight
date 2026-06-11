#include <bits/stdc++.h>
using namespace std;

int main()
{
    string S;
    cin >> S;
    
    int flag = 0;
    bool ans = false;
    if(S.at(0) == 'A'){
        S.at(0) = 'a';
        for(int i=2; i<(int)S.size()-1; i++){
            if(S.at(i) == 'C'){
                S.at(i) = 'c';
                flag += 1;
            }
        }
        if(flag == 1){
            for(int j=0; j<(int)S.size(); j++){
                    if(islower(S.at(j))){
                        ans = true;
                    }else{
                        ans = false;
                        break;
                    }
            }
        }
    }
    if(ans == true){
        cout << "AC" << endl;
    }else{
        cout << "WA" << endl;
    }   
}

