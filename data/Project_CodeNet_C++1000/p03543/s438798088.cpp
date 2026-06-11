#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    string s = to_string(n);
    int cnt = 1;

    for (int i = 1; i < s.size(); ++i) {
        if (s[i] == s[i-1]) {
            ++cnt;
            if (cnt == 3) {
                printf("Yes\n");
                return 0;
            }
        } else
        {
            cnt = 1;
        }        
    } 
    printf("No\n");
}