#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    string a,b,c;
    cin >> a >> b >> c;
    int ans = 0;
    set<char> set1;
    for(int i=0;i<n;i++){
        set1.insert(a[i]);
        set1.insert(b[i]);
        set1.insert(c[i]);
        ans += set1.size()-1;
        set1.clear();
    }
    cout << ans << endl;
}
