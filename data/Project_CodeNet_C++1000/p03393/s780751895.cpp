//
// ~oisín~ C++ Template
//

#include                <bits/stdc++.h>
#define MX_N            500001
#define mp              make_pair
#define mod7            1000000007
#define modpi           314159
#define PI              3.141592653589793238
#define pb              push_back
#define FastIO          ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define All(a)          a.begin(),a.end()
#define fi              first
#define se              second
#define ll              long long int
#define ull             unsigned long long int

int kx[8]  =            {+2, +2, -2, -2, +1, +1, -1, -1};
int ky[8]  =            {+1, -1, +1, -1, +2, -2, +2, -2};
int d9x[9] =            {+1, +1, +1, +0, +0, +0, -1, -1, -1};
int d9y[9] =            {+1, +0, -1, +1, +0, -1, +1, +0, -1};
int dx4[4] =            {+0, +0, +1, -1};
int dy4[4] =            {+1, -1, +0, +0};

ll gcd(ull a, ull b){
    return (a==0)?b:gcd(b%a,a);
}

ll lcm(ull a, ull b){
    return a*(b/gcd(a,b));
}

const long long INF = 1e18;

using namespace std;

string alph = "abcdefghijklmnopqrstuvwxyz";

int main(){
    string rev = alph;
    reverse(All(rev));
    string s;
    cin >> s;
    int n = s.size();
    if(n == 26){
        if(s == rev){
            cout << "-1\n";
            return 0;
        }
        string temp = s;
        next_permutation(All(temp));
        for(int i=0;i<26;++i){
            if(s[i] != temp[i]){
                cout << temp[i] << endl;
                return 0;
            }else{
                cout << temp[i];
            }
        }
        return 0;
    }
    bool in_s[26];
    memset(in_s, 0, sizeof(in_s));
    char ans = 'a';
    for(char c : s){
        in_s[c - 'a'] = true;
    }
    for(char c : alph){
        if(!in_s[c - 'a']){
            ans = c;
            break;
        }
    }
    cout << s + ans << endl;
}
