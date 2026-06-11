#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;


int main(){
    int x, base = -2;
    cin >> x;
    if(x == 0){
        cout << "0\n";
        return 0;
    }
    string s;
    while(x != 0){
        if(x % base == -1){
            s += '1';
            x += base;
        }
        else{
            s += (x%base) + '0';
        }
        x /= base;
    }
    reverse(s.begin(),s.end());
    cout << s;
}
