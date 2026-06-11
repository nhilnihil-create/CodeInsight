#include<iostream>
#include<string>
#include<algorithm>
using namespace std;


string S, T;


int main(void){

    cin >> S >> T; 

    reverse(S.begin(),S.end());
    reverse(T.begin(),T.end());
    int SL = S.length();
    int TL = T.length();

    char SR[SL];
    char TR[TL];

    for (int i = 0; i < SL; i++) SR[i] = S[i];
    for (int i = 0; i < TL; i++) TR[i] = T[i];

    bool exist = false;
    int existpos = 0;

    for (int i = 0; i <= SL - TL;i++){
        int start = i;
        bool jud = false;
        for (int j = 0;j < TL;j++){
//            cout << TR[j] << "," << SR[start + j];
            if (TR[j] == SR[start + j] || SR[start + j] == '?') jud = true;
            else {
                jud = false;
                break;
            }
        }
        if (jud) {
            exist = true;
            existpos = start;
            break;
        }
    } 

    if (exist) {
        for (int i = 0;i < TL; i++) SR[existpos + i] = TR[i];
        for (int i = 0;i < SL; i++) {
            if (SR[i] == '?') SR[i] = 'a';
        }
        string Ans = "";
        for (int i = 0;i < SL; i++) Ans += SR[i];
        reverse(Ans.begin(),Ans.end());
        cout << Ans << endl;
    } else {
        cout << "UNRESTORABLE" << endl;
    }
       return 0;
}