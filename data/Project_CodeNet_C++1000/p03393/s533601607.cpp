#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stdio.h>
#include <queue>
#include <stack>
#include <climits>
#include <map>
#include <set>

using namespace std;

typedef long long ll;
typedef pair<int, int> P;

const ll mod = 1000000007;
const int inf = 1e9;
const long long INF = 1LL << 60;



int main()
{
    string s;
    cin >> s;
    int a[26];
    int n = s.size();
    for(int i = 0; i < 26; i++) a[i] = 0;
    if(s == "zyxwvutsrqponmlkjihgfedcba"){
        cout << -1 << endl;
    }else if(s.size() != 26){
        char c;
        for(int i = 0; i < n; i++){
            a[s[i]-'a']++;
        }
        for(int i = 0; i < 26; i++){
            if(a[i] == 0){
                c = 'a' + i;
                break;
            }
        }
        cout << s + c << endl;
    }else{
        string t = s;
        next_permutation(t.begin(),t.end());
        for(int i = 0; i < 26; i++){
            if(s[i] != t[i]){
                cout << t[i] << endl;
                break;
            }
            cout << s[i];
        }
    }
}