#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<string> s(n);
    for(int i=0; i<n; i++){
        cin >> s[i];
    }

    int ans = 0;
    for(int k=0; k<n; k++){
        bool flag = true;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(s[i][(j+k)%n] != s[j][(i+k)%n]) flag = false;
            }
        }
        if(flag == true) ans += n;
    }
    cout << ans << endl;
    return 0;
}