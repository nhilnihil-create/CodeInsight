#include <iostream>
#include <algorithm>

using namespace std;

long long int calc(string str, int ind) {
    long long int ret=0;
    bool flag=true;
    for(int i=0; i<ind; i++) {
        ret += (long long int)(str[i]-'0');
        // cout << str[i];
    }
    if(ind==str.size()) {
        return ret;
    }
    ret += (long long int)(str[ind]-'0')-1;
    if((long long int)(str[ind]-'0')-1<0) {
        flag=false;
    }
    // cout << (long long int)(str[ind]-'0')-1;
    for(int i=ind+1; i<str.size(); i++) {
        // cout << 9;
        ret += 9;
    }
    // cout << endl;
    if(flag) {
        return ret;
    } else {
        return -1;
    }
}

int main() {
    string N;
    cin >> N;
    long long int ans=0;
    for(int i=0; i<N.size()+1; i++) {
        ans = max(ans, calc(N, i));
    }
    cout << ans << endl;


    return 0;
    
}