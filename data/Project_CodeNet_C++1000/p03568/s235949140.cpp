#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a.at(i);
    }
    int all = 1, bad = 1;
    for(int i = 0; i < n; i++){
        all *= 3;
        if (a.at(i) % 2 == 0)
            bad *= 2;
    }
    cout << all - bad << endl;
}
