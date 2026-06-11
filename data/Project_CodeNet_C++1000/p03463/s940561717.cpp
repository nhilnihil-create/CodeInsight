#include<bits/stdc++.h>
using namespace std;


int main(){
    int n,a,b;
    cin >> n >> a >> b;
    string ans;
    if(abs(b - a) == 1) ans = "Borys";
    else{
        if((abs(b - a) - 1) % 2 == 0) ans = "Borys";
        else ans = "Alice";
    }
    cout <<  ans << endl;

}