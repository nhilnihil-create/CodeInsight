#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin >> n;
    string s=to_string(n);
    string ss=s.substr(0,1);
    int a=s.size();
    int com1=0;
    com1+=stoi(ss)-1;
    com1+=9*(a-1);
    int com2=0;
    while(n>0){
        com2+=n%10;
        n/=10;
    }
    cout << max(com1,com2) << endl;
}