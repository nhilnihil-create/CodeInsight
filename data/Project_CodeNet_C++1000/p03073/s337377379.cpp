#include<bits/stdc++.h>
using namespace std;

int main() {
    string S;
    cin >> S;
    long long ptn0=0; // 0101...
    long long ptn1=0; // 1010...
    for (long long i=0; i<S.size(); i++) {
        if (i%2==0) {
            if (S.at(i)!='0') ptn0++;
            else ptn1++;
        }
        else {
            if (S.at(i)!='1') ptn0++;
            else ptn1++;
        }
    }
    cout << min(ptn0, ptn1) << endl;
}