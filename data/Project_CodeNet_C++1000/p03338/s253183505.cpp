#include <bits/stdc++.h>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
using namespace std;
 
int main() {
    //input
    int n;cin >> n;
    string str; cin >> str;
    vector<char> alp{'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    vector<int> f(100,0);
    vector<int> l(100,0);
    vector<int> count(100,0);
    vector<int> ex(100,0);
 
    //compute
    int ans;
    ans = 0;
 
    for(int j = 0; j < 26; j++){
        for(int i = 0; i < n; i++){
            if(str.at(i) == alp[j]){
                f[j] = i;
                ex[j] = 1;
                break;
            }
        }
        for(int i = 0; i < n - 1;i++){
            if(str.at(n - 1 - i) == alp[j]){
                l[j] = n - 1 - i;
                break;
            }
                
    }
    }

    for(int i = 0; i < 26; i++) {
        if(l[i] < f[i]){
        }else if(ex[i] == 1){        
            for(int j = 0; j < l[i] - f[i] ;j++){
                count[f[i] + j] += 1;
            }
        }
    }

    sort(count.rbegin(),count.rend());

    ans = count[0];

    //output
    cout << ans << endl;

}