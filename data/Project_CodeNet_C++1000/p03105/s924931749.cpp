#include <bits/stdc++.h>

using namespace std;

int main() {

    int A, B, C;
    int asn = 0;

    cin >> A >> B >> C;

    while(B >= A) {
        
        if(asn == C) break;
        asn++;
        B -= A;
    }

    cout << asn << endl;
    return 0;
}
