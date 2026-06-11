#include <bits/stdc++.h>
using namespace std;
int main(){
    int a;
    int ma = 0, mi = 101;
    for (int i = 0; i < 3; i++){cin >> a; ma = max(ma, a); mi = min(mi, a);}
    cout << ma-mi << endl;
    return 0;
}