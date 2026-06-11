#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    
    int N, x;
    cin >> N >> x;
    vector<int> l(N);
    for(int i = 0; i < N; i++){
        cin >> l[i];
    }
    
    sort(l.begin(), l.end());
    
    int ans = 0;
    
    for(int i = 0; i < N; i++){
        x -= l[i];
        if(x >= 0) ans++;
        else break;
    }
    
    if(x > 0) cout << ans - 1 << endl;
    else cout << ans << endl;
    
}
