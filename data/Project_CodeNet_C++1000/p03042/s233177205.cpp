#include <bits/stdc++.h>
#define rep(i,n) for (int i =0; i < (n); ++i)
using namespace std;

int main() {
        string s;
        cin >> s;
        int f, b;
        int ff=0;

        f  =  (s[0] - '0') * 10;
        f +=   s[1] - '0';
        b  =  (s[2] - '0') * 10;
        b +=   s[3] - '0';

        if (f < 13 && f > 0) {
                ff = 1;
        }
        if (b < 13 && b > 0) {
                ff += 10;
        }

        switch (ff) {
                case 11:
                        cout << "AMBIGUOUS" << endl;
                        break;
                case 0:
                        cout << "NA" << endl;
                        break;
                case 1:
                        cout << "MMYY" << endl;
                        break;
                case 10:
                        cout << "YYMM" << endl;
                        break;
        }
        return 0;
}

