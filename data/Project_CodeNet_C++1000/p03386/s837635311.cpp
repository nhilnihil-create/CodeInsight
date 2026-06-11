#include <bits/stdc++.h>
using namespace std;

int main(){
    int a, b, k; cin >> a >> b >> k;
    set<int> reg;
    for(int i = a; i <= min(a+k-1,b); i++) {
        reg.insert(i);
    }
    for(int i = max(b-k+1,a); i <= b; i++) {
        reg.insert(i);
    }
    auto itr = reg.begin();
    for(int i = 0; i < reg.size(); i++) {
        cout << *itr << endl;
        itr++;
    }
    return 0;
}