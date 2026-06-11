#include <cstdio>
#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <cmath>
#include <functional>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#define rep(i,n) for (int i=0;i<n;i++)
using ll = long long;
using namespace std;

void solve(){

}
int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    string t;
    cin >> s >> t;
    int sl = s.size();
    int tl = t.size();

    int smin = min(sl,tl);

    sort(s.begin(),s.end());
    sort(t.begin(),t.end(),greater<int>());


    if(s<t){
        cout << "Yes";
    }
    else{
        cout << "No";
    }



    return 0;
}