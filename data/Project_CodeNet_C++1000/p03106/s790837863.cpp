#include <iostream>
#include <set>
using namespace std;
int main() {
    int a, b, k;
    cin >> a >> b >> k;
    int g=max(a,b), l=min(a,b);
    set<int> st1, st2;
    for (int i=1; i*i<=g; i++) {
        if (g%i == 0) {
            st1.insert(i);
            st1.insert(g/i);
        }
        if (l%i == 0) {
            st2.insert(i);
            st2.insert(l/i);
        }
    }
    set<int>::reverse_iterator itr=st2.rbegin();
    int cnt = 0;
    while (itr != st2.rend()) {
        if (st1.find(*itr) != st1.end()) {
            cnt++;
            if (cnt == k) {
                cout << *itr << endl;
                return 0;
            }
        }
        itr++;
    }

}