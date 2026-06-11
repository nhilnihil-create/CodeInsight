#include <bits/stdc++.h>
using namespace std;
#define N_MAX 100000

int main(){
//入力
string s;
int ans=0;

    cin >> s ;
    //部分文字列の開始位置指定
    for(int i=0;i<s.length();i++){
        //ACGT文字列であるような終了文字までループ
        for(int j=i;j<s.length();j++){
            if(s[j]=='A'||s[j]=='C'||s[j]=='G'||s[j]=='T') ans=max(ans,j-i+1);
            else break;
        }
    }

    cout <<ans <<endl;
    return 0;
}