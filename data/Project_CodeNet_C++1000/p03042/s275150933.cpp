#include <bits/stdc++.h>
using namespace std;

int main() {
    int s;
    cin >> s;
    int fir = s / 100;
    int sec = s % 100;
    /*
    string s;
    cin >> s;
    int fir = (s[0] - '0') * 10 + s[1] - '0';
    int sec = (s[2] - '0') * 10 + s[3] - '0';
    */
   if (fir >= 1 && fir <= 12) {
       if (sec >= 1 && sec <= 12) {
           cout << "AMBIGUOUS" << endl;
       }
       else {
           cout << "MMYY" << endl;
       }
   }
   else {
       if (sec >= 1 && sec <= 12) {
           cout << "YYMM" << endl;
       }
       else {
           cout << "NA" <<endl;
       }
   }
    return 0;
}