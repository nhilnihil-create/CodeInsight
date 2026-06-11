#include <bits/stdc++.h>
using namespace std;
int main(){
    int x = 0,a = 0,i = 0;
    string S;
    cin >> S;
    for(i = 0;i < S.size();i++){
        if (S[i] == 'A' || S[i] == 'C' || S[i] == 'G' || S[i] == 'T'){
            x++;
            if(a < x){
                a = x;
            }
        }
        else{
            x = 0;
        }
    }
    cout << a << endl;
}