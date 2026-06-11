#include <bits/stdc++.h>
using namespace std;

int main(){
    string S;
    cin >> S;
    int counter=0;
    int ans=0;
    for(int i=0; i<S.size(); i++){
        if(S.at(i)=='A'||S.at(i)=='C'||S.at(i)=='G'||S.at(i)=='T') counter++;
        else counter=0;

        if(counter>ans) ans=counter;
    }
    cout << ans << endl;
}