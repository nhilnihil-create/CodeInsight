#include<iostream>
#include<string>
using namespace std;
int main(){
    string str;
    cin >> str;
    int n;
    n = str.size();
    int c0,c1;
    c0 = 0;
    c1 = 0;
    for(int i=0; i<n; i++){
        if(str[i]=='0'){
            c0++;
        }else{
            c1++;
        }
    }
    cout << 2*min(c0,c1) << endl;
}

