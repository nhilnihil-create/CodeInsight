#include <bits/stdc++.h>

#define ll long long int
#define ld long double
using namespace std;

int main(){
    string s;
    cin >> s;
    int a = (s[0] - '0') * 10 + (s[1] - '0');
    int b = (s[2] - '0') * 10 + (s[3] - '0');
    bool yymm = false, mmyy = false;
    if(0 < b && b < 13) yymm = true;
    if(0 < a && a < 13) mmyy = true;
    if(yymm && mmyy){
        cout << "AMBIGUOUS" << endl;
    }
    else if(yymm){
        cout << "YYMM" << endl;
    }
    else if(mmyy){
        cout << "MMYY" << endl;
    }
    else{
        cout << "NA" << endl;
    }
    return 0;
}
