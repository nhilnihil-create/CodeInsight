#include <bits/stdc++.h>
using namespace std;

int main(void){
    
    int N,K;
    string s;
    cin >> N >> K >> s;
    s[K-1] += ('a' - 'A');
    cout << s << endl;
}