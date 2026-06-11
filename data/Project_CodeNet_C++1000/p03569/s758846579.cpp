#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll MOD = 1000000007;
const ld PI = acos(-1);  
const ld EPS = 0.0000000001;


int main(){
    string s, t;   cin >> s;
    t = s;

    reverse(t.begin(), t.end());
    int left=0, right=0, cnt=0, n=s.size();
    while(left<n || right<n){
        if(s[left]==t[right]){
            left += 1; right += 1;
        }else if(s[left]=='x'){
            cnt += 1;   left += 1;
        }else if(t[right]=='x'){
            cnt += 1;   right += 1;
        }else{
            cnt = -1; break;
        }
    }
    if(0<cnt) cnt /= 2;
    cout <<cnt << endl;
}

