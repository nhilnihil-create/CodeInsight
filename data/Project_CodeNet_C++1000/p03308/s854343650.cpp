#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int mini = 1000000000;
    int maxa = 0;
    for(int i = 0; i < n; i++) {
        int a; cin >> a;
        mini = min(mini,a);
        maxa = max(maxa,a);
    }
    cout << maxa - mini << endl;
}
