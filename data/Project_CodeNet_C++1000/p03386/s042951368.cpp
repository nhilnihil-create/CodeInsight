#include <bits/stdc++.h>
using namespace std;
int main(){
    long a,b,k;
    cin >> a >> b >> k;
    vector <long> ans;
    for(long i = a; i <= b; i++){
        if( ((i-a+1)<=k)||
            ((b-i+1)<=k)){
            //ans.push_back(i);
            cout << i << endl;
        }
    }
    return 0;
}