#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    int a,b;
    string s;
    cin >> a >> b;
    cin >> s;
    for(int i=0; i<a; i++){
        if(s[i]=='-'){
            cout << "No";
            return 0;
        }
    }
    if(s[a]!='-'){
        cout << "No";
        return 0;
    }
    for(int i=a+1; i<=a+b; i++){
        if(s[i]=='-'){
            cout << "No";
            return 0;
        }
    }
    cout << "Yes";


}
