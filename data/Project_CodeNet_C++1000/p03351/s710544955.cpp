#include<bits/stdc++.h>
using namespace std;
int main(){
    int a, b, c, d;
    bool bl;
    cin >> a >> b >> c >> d;
    if(abs(c-a) <= d){
        cout << "Yes" << endl;
    }else if(abs(a-b) <= d && abs(c-b) <= d){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}