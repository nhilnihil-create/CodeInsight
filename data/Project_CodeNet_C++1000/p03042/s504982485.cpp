#include<bits/stdc++.h>
using namespace std;
int main(){
    int S,a,b;
    cin >> S;
    a = S/100;
    b = S%100;
    if(a!=0 && a<=12){
        if(b!=0 && b<=12)cout << "AMBIGUOUS" << endl;
        else cout << "MMYY" << endl;
    }
    else{
        if(b!=0 && b<=12)cout << "YYMM" << endl;
        else cout << "NA" << endl;
    }
}