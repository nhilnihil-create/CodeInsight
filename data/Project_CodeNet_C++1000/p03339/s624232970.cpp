#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n;
    string s;
    cin >> n >> s;
    vector<int> W(n, 0), E(n, 0);
    for(int i=0; i<n-1; i++){
        W[i+1] = W[i] + (s[i] == 'W');
    }
    int ans = W.back();
    for(int i=n-1; i>=1; i--){
        E[i-1] = E[i] + (s[i] == 'E');
        ans = min(ans, W[i-1] + E[i-1]);
    }
    cout << ans << endl;
    return 0;
}