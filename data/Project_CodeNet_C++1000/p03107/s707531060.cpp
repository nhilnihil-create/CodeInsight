#include <bits/stdc++.h>
using namespace std;

int main(){
    
    string s;
    cin >> s;
    int count0=0, count1=0;

    for(int i=0; i<s.size(); i++){
        if(s.at(i)=='0') count0++;
        if(s.at(i)=='1') count1++;
    }
    cout << 2*min(count0,count1) << endl;
}