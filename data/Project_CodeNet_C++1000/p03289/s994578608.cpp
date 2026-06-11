#include<bits/stdc++.h>
using namespace std;
int main(){
    string S;
    cin >> S;
    if(S[0]!='A'){
        cout << "WA" << endl;
        return 0;
    }
    else{
        int flag=0;
        int flag2=0;
        for(int i=1;i<S.length();i++){
            if(i>=2 && i<S.length()-1 && S[i]=='C')flag++;
            else if((int)(S[i]-'a')<0 || (int)(S[i]-'a')>26)flag2++;
        }
        if(flag!=1 || flag2>0)cout << "WA" << endl;
        else cout << "AC" << endl;
    }
}