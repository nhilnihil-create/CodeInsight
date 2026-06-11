#include <bits/stdc++.h>

typedef long long   ll;
typedef long double ld;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    string s;
    cin >> n >> s;
    int wc=0;
    for(int i = 0; i < n; i++) {
        if(s[i]=='W') wc++;
    }

    int count=0;
    int chm=INT32_MAX;
    for(int i = 0; i < n; i++) {
        int cht;
        if(s[i]=='W'){
            cht=count + n-i-wc+count;
            count++;
        }
        else{
            cht=count + n-i-wc+count-1;
        }
        chm=min(chm,cht);
    }
    cout << chm << "\n";
    return 0;
}