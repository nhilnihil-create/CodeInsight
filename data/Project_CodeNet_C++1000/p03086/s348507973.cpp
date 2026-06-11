#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    int cmax = 0,count = 0;
    cin >> s;
    for(int i=0; i<int(s.size());i++){
        if(s[i]=='A' || s[i]=='C' || s[i]=='G' || s[i]=='T'){
            count++;
        }else{
            cmax = max(cmax,count);
            count=0;
        }
    }
    cmax = max(cmax,count);
    cout << cmax << '\n';
}
