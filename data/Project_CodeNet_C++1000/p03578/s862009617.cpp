#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <string>
using namespace std;
 
int main() {
    //input
    int n;cin >> n;
    vector<int> d(n + 1);for(int i = 1; i < n + 1;i++) cin >> d[i];
    int m;cin >> m;
    vector<int> t(m + 1);for(int i = 1; i < m + 1;i++) cin >> t[i];

    if(m > n){
        cout << "NO" << endl;
        return 0;
    }
 
    //compute
    multiset<int> st1,st2;
    for(int i = 1; i < n + 1;i++) st1.insert(d[i]);
    for(int i = 1; i < m + 1;i++) st2.insert(t[i]);

    //output
    if (includes(st1.begin(), st1.end(),st2.begin(), st2.end())){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }

}