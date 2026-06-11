#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

int main(){
    int a,b;
    string s;
    cin >> a >> b >> s;
    bool ok = true;
    for(int i=0;i<a;i++){
        if(s[i] < '0' || s[i] > '9'){
            cout << "No" << endl;
            return 0;
        }
    }
    if(s[a] != '-'){
        cout << "No" << endl;
        return 0;
    }

    for(int i=a+1;i<a+b+1;i++){
        if(s[i] < '0' || s[i] > '9'){
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;

}