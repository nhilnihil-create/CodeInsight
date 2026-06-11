#include<bits/stdc++.h>
using namespace std; 

int main() {
  
    int n, m, x;
    int s = 0;
    
    cin >> n >> m;

    vector<int> vs(n);
    
    for(int i = 0; i < n; i++){
        cin >> vs[i];
    }

    for(int i = 0; i < n; i++){
        s += vs[i];
    }

    sort(vs.begin(), vs.end());
    x  = m - s;

    cout << n+x/vs[0] << endl;
    
    return 0;
}
