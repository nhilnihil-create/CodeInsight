#include <bits/stdc++.h>
using namespace std;

int main(){
    int s;
    bool yymm = 1;//〇年〇月
    bool mmyy = 1;//〇月〇年
    cin >> s;
    if(s/100 > 12 || s/100 == 0)mmyy = 0;
    if(s%100 > 12 || s%100 == 0)yymm = 0;

    if(yymm && mmyy)cout << "AMBIGUOUS" << endl;
    if(!(yymm) && mmyy)cout << "MMYY" << endl;
    if(yymm && !(mmyy))cout << "YYMM" << endl;
    if(!(yymm) && !(mmyy))cout << "NA" << endl;
}