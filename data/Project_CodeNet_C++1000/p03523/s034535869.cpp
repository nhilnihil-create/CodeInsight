#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> PL;

const int INT_INF = 2147483646;
const ll LL_INF = 9223372036854775807;


const int SIZE = 1e5+100;
string s, ss;

int main(){
    cin >> s;
    ss = "AKIHABARA";

    int f = 1;
    ll num = 0, num1 = 0;
    while(true){
        if(s[num] != ss[num1]){
            if(ss[num1] != 'A'){
                f = 1;
                break;
            }
            ++num1;
        }
        else{
            if(num < s.length())    ++num;
            if(num1 < ss.length())  ++num1;
        }
        if(num == s.length() && num1 == ss.length()){
            f = 0;
        }
        if(num == s.length() && num1 == ss.length()){
            break;
        }
        
    }

    if(f == 0){
        cout << "YES\n";
    }
    else{
        cout << "NO\n";
    }
}