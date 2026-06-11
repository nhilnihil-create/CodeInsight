#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, a, b;
    cin >> n >> a >> b;

    int amax = min(a,b);
    int amin = max(0, a+b-n);
    cout << amax << " " << amin << endl;
    return 0;
}