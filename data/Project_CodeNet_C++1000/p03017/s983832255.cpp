#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <queue>
#include <map>
#define ll long long

using namespace std;

int main(void){
    ll n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    string s;
    cin >> s;
    s.insert(0, "#");
    s.push_back('#');
    bool ans = true;
    if(c < d){
        for(ll i = a; i <= d-1; i++){
            if(s[i]=='#' && s[i+1]=='#')
                ans = false;
        }
    }
    else if(c > d){
        ans = false;
        for(ll i = b; i <= d; i++){
            if(s[i-1]=='.' && s[i]=='.' && s[i+1]=='.')
                ans = true;
        }
        for(ll i = a; i <= c-1; i++){
            if(s[i]=='#' && s[i+1]=='#')
                ans = false;
        }
    }
    if(ans == true)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}
