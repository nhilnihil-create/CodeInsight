#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    
    int sum = 0;
    int maxp = 0;
    
    for (int i = 0; i < n; i++) {
        int buf;
        cin >> buf;
        sum += buf;
        maxp = max(maxp,buf);
    }
    
    cout << sum - maxp / 2 << endl;
    
    return 0;
}
