#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

//#define int long long
//signed main(){
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    int n=s.size();
    int l=0;
    int r=n-1;
    int cnt=0;
    while(r-l>0) {
        if(s[l]==s[r]){
            l++;
            r--;
        }
        else{
            if(s[l]=='x'){
                l++;
                cnt++;
            }
            else if(s[r]=='x'){
                r--;
                cnt++;
            }
            else{
                cout << "-1" << "\n";
                return 0;
            }
        }
    }
    cout << cnt << "\n";
    return 0;
}