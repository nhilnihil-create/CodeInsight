#include<bits/stdc++.h>
using namespace std;
int main(){
    int s;
    cin >> s;
    int a,b;
    a = s/100;
    b = s - a*100;
    bool ym,my;
    ym = true;
    my = true;
    if(0== a || a>= 13) my = false;
    if(0== b || b>= 13) ym = false;
    if(ym == true && my == true) cout << "AMBIGUOUS" << endl;
    if(ym == true && my == false) cout << "YYMM" << endl;
    if(ym == false && my == true) cout << "MMYY" << endl;
    if(ym == false && my == false) cout << "NA" << endl;
}
