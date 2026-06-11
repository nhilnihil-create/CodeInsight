#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    string f="",b="";
    f += s.at(0);
    f += s.at(1);
    b += s.at(2);
    b += s.at(3);
    int inf,inb;
    inf = atoi(f.c_str());
    inb = atoi(b.c_str());
    //cout << inf << inb <<endl;
    if((inf>=13||inf==0)&&inb<=12&&inb>=1){
        cout << "YYMM" << endl;
    }else if(inf<=12&&inb<=12&&inf>=1&&inb>=1){
        cout << "AMBIGUOUS" << endl;
    }else if((inb>=13||inb==0)&&inf<=12&&inf>=1){
        cout << "MMYY" << endl;
    }else{
        cout << "NA" << endl;
    }
}