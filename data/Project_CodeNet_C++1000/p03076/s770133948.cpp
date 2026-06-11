#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int a,sum;
    int frac,minfrac = 10;    
    sum = 0;
    for(int i=0;i<5;i++) {
        cin >>a;
        if(a%10) {
            sum += (((a/10)+1)*10);
            frac = a %10;
            if(minfrac > frac) {
                minfrac = frac;
            }
        } else {
            sum += ((a/10)*10);
        }
    }

    if(minfrac % 10){
        sum  = sum - 10 + minfrac;
    }

    cout << sum << endl;
    return 0;
}
