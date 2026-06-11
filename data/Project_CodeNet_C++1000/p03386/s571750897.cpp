#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int A,B,K;

    cin >> A  >> B >> K;
    set<int> s;
    for(int i=0;i<K;i++) {
        if((A+i) <= B) s.insert(A+i);
        if((B-i) >= A) s.insert(B-i);
    }

    for(auto i:s) {
        cout << i << endl;
    }
    return 0;
}
