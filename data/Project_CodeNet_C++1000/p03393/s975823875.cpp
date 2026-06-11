#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> iint;
typedef pair<ll,ll> llll;
#define ALL(x) (x).begin(),(x).end()
const ll zero = 0;
const ll INF = 9223372036854775807; //10^18
const int inINF = 2147483647; //10^9
const ll MOD = 1000000007; //10^9+7
const ll MOD2 = 998244353;
void Yes() {printf("Yes\n");}
void No() {printf("No\n");}
void YES() {printf("YES\n");}
void NO() {printf("NO\n");}

int main(){
    string s;
    cin >> s;
    if(s == "zyxwvutsrqponmlkjihgfedcba"){
        printf("-1\n");
        return 0;
    }
    vector<int> c(26, 0);
    for (int i = 0; i < s.length(); i++) {
        c[s[i] - 'a']++;
    }
    int ii = 26;
    for (int i = 0; i < 26; i++) {
        if(c[i] == 0){
            ii = i;
            break;
        }
    }
    if(ii != 26){
        s += 'a' + ii;
        printf("%s\n", s.c_str());
        return 0;
    }

    int ind = s.length() - 1;
    while(true){
        while(s[ind] == 'z'){
            s = s.substr(0, ind);
            ind--;     
            c[25]--;     
        }
        auto t = s[ind] - 'a';
        t++;
        s[ind] = t + 'a';
        c[t-1]--;
        c[t]++;
        bool check = true;
        for (int i = 0; i < 26; i++) {
            if(c[i] > 1) check = false;   
        }
        if(check) break;
    }
    printf("%s\n", s.c_str());


}