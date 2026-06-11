#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define put(i) cout<<fixed<<i<<endl
using namespace std;
using ll = long long;

int main(){
    char b; cin >> b;

    if(b == 'A') put('T');
    else if(b == 'C') put('G');
    else if(b == 'G') put('C');
    else if(b == 'T') put('A');    
}