#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>
#include <string>

#define reps(i,s,n) for(int (i) = (s); (i) < (n); (i)++)
#define rep(i,n) reps(i,0,n)
using namespace std;
using ll = long long;

int main(){
    string s,t;
    cin >> s >> t;
    vector<int> as(26,0),at(26,0);
    int slen = s.length();
    int tlen = t.length();
    rep(i,slen){
        as[s[i]-'a']++;
    }
    rep(i,tlen){
        at[t[i]-'a']++;
    }
    // rep(i,26){
    //     cout << as[i] << " ";
    // }
    // cout << endl;

    // rep(i,26){
    //     cout<< at[i] << " ";
    // }
    // cout << endl;


    string al = "abcdefghijklmnopqrstuvwxyz";

    string ss="",tt="";
    rep(i,26){
        rep(j,as[i]){
            ss += al[i];
        }
    }
    rep(i,26){
        rep(j,at[25-i]){
            tt += al[25-i];
        }
    }
    //cout << ss << " " << tt << endl;
    if(ss < tt){
        cout << "Yes"  <<endl;
    }else{
        cout << "No" << endl;
    }

    return 0;
}