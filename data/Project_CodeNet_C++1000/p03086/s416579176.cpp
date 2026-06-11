#include <iostream>
using namespace std;

int main(){
    string s;
    cin >> s;

    int n=s.size(), tmp=0, maxlen=0;

    for(int i=0; i<n; i++){
        if(s[i]=='A' || s[i]=='C' || s[i]=='G' || s[i]=='T' ){
            tmp++;
        } else {
            tmp=0;
        } 
        maxlen = max (maxlen, tmp);
    }

    cout << maxlen << endl;

    return 0;
}