#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define all(v) v.begin(), v.end()

int main(){
    string S;
    cin >> S;
    int c0 = count(all(S),'0');
    int c1 = count(all(S),'1');
    int cm=min(c0,c1);
    
    cout << 2*cm << endl;
} 
