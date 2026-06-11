#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n,q;
    cin >> n >> q;
    string s; cin >> s;
    vector<int> vec(n);
    for(int i = 1; i < n; i++){
        if(s[i] == 'C' && s[i-1] == 'A') vec[i] = vec[i-1]+1;
        else vec[i] = vec[i-1];
    }
    for(int i = 0; i < q; i++){
        int l,r; cin >> l >>r;
        l--; r--;
        int ans = vec[r]-vec[l];
        if(l != 0 && vec[r]=='A' && vec[r+1]=='C') ans--;
        cout << ans << endl;
    }
    return 0;
}
