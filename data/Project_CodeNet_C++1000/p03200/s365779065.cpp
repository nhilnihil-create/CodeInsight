#include<iostream>
using namespace std;

int main(){
    long long backBlack, ans = 0;
    bool yetWhite = true;
    string S;
    cin >> S;
    backBlack = S.length() - 1;

    for(int i=S.length()-1; i>= 0; i--){
        if(S[i] == 'W') yetWhite = false;
        if(yetWhite) backBlack--;
        
        if(S[i] == 'B' && !yetWhite){
            ans += backBlack - i;
            backBlack--;
        }
    }

    cout << ans << endl;
}