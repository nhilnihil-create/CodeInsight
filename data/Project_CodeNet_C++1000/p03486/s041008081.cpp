#include <bits/stdc++.h>
#include <vector>
#include <queue>
#include <iostream>
#include <iomanip>
using namespace std;
typedef long long LL;
#define REP(i,n) for(int i=0;i<n;i++)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)

int main(){
    string s, t;
    cin >> s;
    cin >> t;

    vector<char> s_char((int)s.size());
    vector<char> t_char((int)t.size());

    REP(i,(int)s.size()){
        s_char[i]=s[i];
    }

    REP(i,(int)t.size()){
        t_char[i]=t[i];
    }

    sort(s_char.begin(), s_char.end());
    sort(t_char.begin(), t_char.end(), greater<char>());

    string s_next = "";
    string t_next = "";

    REP(i,(int)s.size()){
        s_next += s_char[i];
    }

    REP(i,(int)t.size()){
        t_next += t_char[i];
    }

    if(s_next < t_next){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;

}