#include <bits/stdc++.h> 
using namespace std; 
typedef long long int ll;
typedef unsigned long long int ull;
const long long int m=pow(10,9)+7;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    string t="keyence";
    ll n=s.length();
    for(ll l=0;l<n;l++){
        for(ll r=l;r<n;r++){
            string ans=s.substr(0,l)+s.substr(r,n-r);
            if(ans==t){
                cout << "YES" << endl;
                return 0;
            }
        }
    }
    cout << "NO" << endl;
    return 0;
}