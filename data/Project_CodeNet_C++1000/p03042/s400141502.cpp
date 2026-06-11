#include<bits/stdc++.h>
using namespace std; 
int main(){
    int s; cin>> s;
    int a = s / 100;
    int b = s - a * 100;
    int ja=0, jb=0;
    if(b >= 13 || b <= 0) jb=1;
 
    if(a >= 13 || a<=0) ja=1;
 
    if(jb == 0 && ja == 0) cout<< "AMBIGUOUS" << endl;
    else if(jb == 1 && ja == 0) cout<< "MMYY" << endl;
    else if(jb == 0 && ja == 1) cout<< "YYMM" << endl;
    else cout<< "NA" << endl;
}