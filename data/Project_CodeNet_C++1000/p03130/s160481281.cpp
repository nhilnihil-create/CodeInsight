#include <bits/stdc++.h>
using namespace std;

int main() {
    int s[5];
    for(int i=0;i<5;i++) s[i]=0;
    for(int i=0;i<6;i++){
        int a;
        cin >> a;
        s[a]++;
    }
    if(s[1]<=2&&s[2]<=2&&s[3]<=2&&s[4]<=2) cout << "YES" <<endl;
    else cout << "NO" << endl;
}