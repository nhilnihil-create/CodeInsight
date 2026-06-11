#include<bits/stdc++.h>
using namespace std;

int main(void){
    int s;
    cin >> s;
    int fy = 1, fm = 1;
    int sf = s / 100, sb = s % 100;
    if(sb == 0 || sb > 12) fy = 0;
    if(sf == 0 || sf > 12) fm = 0;
    if(fy && !fm) cout << "YYMM" << endl;
    else if(!fy && fm) cout << "MMYY" << endl;
    else if(fy && fm) cout << "AMBIGUOUS" << endl;
    else cout << "NA" << endl;
    return 0;
}