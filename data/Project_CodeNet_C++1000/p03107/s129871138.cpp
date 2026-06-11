#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    string s;
    cin >> s;
    int n = s.size();
    int zero = 0;
    int one = 0;
    for(int i=0 ; i<n; i++){
        if(s.at(i) == '0') zero++;
        else one++;
    }
    cout << 2*min(zero,one) << endl;
}