#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void){
    string s;
    cin >> s;
    int n = (int)s.size();

    int n0 = 0, n1 = 0;
    for(int i=0;i<n;i++){
        if(s[i]=='0') n0++;
        else n1++;
    }
    cout << n - abs(n0-n1) << endl;
    return 0;
}