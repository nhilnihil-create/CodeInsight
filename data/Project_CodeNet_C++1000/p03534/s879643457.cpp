#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <string>
#include <array>

using namespace std;

int gcd(int a, int b) {
    int r;
    while (b != 0) {
        r = a % b;
        a = b; 
        b = r;
    }
    return a;
}

int main()
{
    string s, ans;
    cin >> s;
    vector<int> count(3, 0);
    bool a, b, c, d;
    a = false;
    b = false;
    c = false;
    d = false;
    int l = s.length();
    for(int i=0; i<l; ++i){
        count[s[i] - 'a']++;
        if(s[i] == 'a'){
            a = true;
        }
        if(s[i] == 'b'){
            b = true;
        }
        if(s[i] == 'c'){
            c = true;
        }
    }
    // 1
    if((a && !b && !c) || (!a && b && !c) || (!a && !b && c)){
        ans = (l == 1) ? "YES" : "NO";
    }
    // 2
    else if((a && b && !c) || (a && !b && c) || (!a && b && c)){
        ans = (l <= 2) ? "YES" : "NO";
    }
    // 3
    else if(a && b && c){
        d = (abs(count[0] - count[1]) <= 1) && (abs(count[1] - count[2]) <= 1) && (abs(count[2] - count[0]) <= 1);
        ans = d ? "YES" : "NO";
    }
    cout << ans << endl;
}
