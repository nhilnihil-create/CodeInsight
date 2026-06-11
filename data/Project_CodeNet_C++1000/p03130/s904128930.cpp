#include <bits/stdc++.h>
using namespace std;

int main() {
    int count[5]={};
    for(int i=0;i<3;i++){
        for(int j=0;j<2;j++){
            int s;
            cin >> s;
            count[s]++;
        }
    }
    int ans = 0;
    for(int i=1;i<5;i++){
        if(count[i]%2==0)ans++;
    }
    if(ans==2) cout << "YES" << endl;
    else cout << "NO" << endl;
}

