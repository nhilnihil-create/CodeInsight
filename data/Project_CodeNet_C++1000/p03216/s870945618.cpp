#include<bits/stdc++.h>

using namespace std;


int main(void) {
    long n;
    cin >> n;
    string s;
    cin >> s;
    long q;
    cin >> q;

    for(int i=0; i<q; i++) {
        long k;
        cin >> k;

        long r = 0, d = 0, m = 0, dm = 0;
        for(int i=0; i<n; i++) {
            if(i-k >= 0) {
                switch(s[i-k]) {
                    case 'D':
                        d--;
                        dm -= m;
                        break;
                    case 'M':
                        m--;
                        break;
                }
            }
            switch(s[i]) {
                case 'D':
                    d++;
                    break;
                case 'M':
                    m++;
                    dm += d;
                    break;
                case 'C':
                    r += dm;
                    break;
            }


        }
        cout << r << endl;
    }
}
