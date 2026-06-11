#include<bits/stdc++.h>
using namespace std;
#define itn int

int main(void){
    string t;
    cin >> t;
    
    int a = 0,b = 0;
    for(int i = 0;i < t.size();i++){
        if(t[i] == '0')a++;
        else b++;
    }
    
    cout << min(a,b)*2 << endl;
}