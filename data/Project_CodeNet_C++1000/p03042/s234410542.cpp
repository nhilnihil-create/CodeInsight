#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
//Shift+Command+bでデバッグ
//その後ターミナルで./a.outを実行
//入力を貼り付ける

//////////////////
//  A
/*int main(void){
    int n,k;
    string s;
    cin >> n>>k>>s;

    for(int i=0 ;i<n;i++){
        if(i+1==k){
            if(s[i]=='A') cout<<'a';
            else if(s[i]=='B') cout<<'b';
            else cout<<'c';
        }else{
            cout<<s[i];
        }
    }
    cout<<endl;

    return 0;
}*/
//////////////////
//  B
int main(void){
    string s;
    cin >> s;
    int a=stoi(s)/100,b=stoi(s)%100;

    if(a==0){
        if(b==0) cout << "NA" <<endl;
        else if(b<=12) cout << "YYMM" <<endl;
        else cout<<"NA"<<endl;
    }else if(a<=12){
        if(b==0) cout << "MMYY" <<endl;
        else if(b<=12) cout << "AMBIGUOUS" <<endl;
        else cout<<"MMYY"<<endl;
    }else{
        if(b==0) cout << "NA" <<endl;
        else if(b<=12) cout << "YYMM" <<endl;
        else cout<<"NA"<<endl;
    }
    return 0;
}
//////////////////
//  C
/*int main(void){

    return 0;
}*/
//////////////////
//  D
/*int main(void){

    return 0;
}*/
//////////////////
//  E
/*int main(void){

    return 0;
}*/
//////////////////
//  F
/*int main(void){

    return 0;
}*/
