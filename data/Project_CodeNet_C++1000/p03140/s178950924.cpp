#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007

int main(){
    int n; cin >> n;
    string a,b,c; cin >> a >> b >> c;
    int cnt = 0;
    for(int i = 0; i < n; i++){
        if(a[i] == b[i] && b[i] == c[i]) continue;
        else if((a[i] == b[i] && b[i] != c[i]) || (b[i] == c[i] && a[i] != b[i]) || (c[i] == a[i] && c[i] != b[i])) cnt++;
        else cnt += 2;
    }
    cout << cnt << endl;
    return 0;
}