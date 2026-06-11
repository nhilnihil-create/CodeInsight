#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    string a,b;
    cin >> a >> b;
    bool f = true;
    for(int i = 0; i < 3; i++){
        if(a[i] != b[2 - i]){
            f = false;
            break;
        }
    }
    if(f) puts("YES");
    else puts("NO");
}