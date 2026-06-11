#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int mod = 1e9+7;

int main(){
    string s;
    cin >> s;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == 'A') cout << 'T';
        else if(s[i] == 'T') cout << 'A';
        else if(s[i] == 'G') cout << 'C';
        else if(s[i] == 'C') cout << 'G';
    }    
}