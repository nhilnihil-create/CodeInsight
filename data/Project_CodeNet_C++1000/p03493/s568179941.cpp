#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    int cnt=0;
    cin >> s;

    int length = (int)s.length();

    for(int i =0; i<length; i++)
        if(s[i] == '1')
            cnt++;
    
    cout << cnt << endl;
}