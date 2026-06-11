#include<bits/stdc++.h>
using namespace std;

int main(void){
    int n,k;
    char s[60];

    cin >> n >> k >> s;
    s[k-1] += 32;
    
    cout << s << endl;
    return 0;


}