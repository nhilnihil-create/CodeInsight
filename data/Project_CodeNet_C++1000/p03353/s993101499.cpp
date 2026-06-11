#include <bits/stdc++.h>
using namespace std;
 
int main(){
    string s;
    int k;
    cin >> s >> k;
 
    int n = s.length();
    vector<string> substrings;
    for(int i=1; i<=5; i++){
        for(int j=0; j<=n-i; j++){
            substrings.push_back(s.substr(j,i));
        }
    }
    sort(substrings.begin(), substrings.end());
    
    int count = 0;
    for(int i=0; i<n*(n+1)/2; i++){
        if(i >= 1 && substrings[i] == substrings[i-1]) continue;
 
        count += 1;
        if(count == k){
            cout << substrings[i] << endl;
            return 0;
        }
    }
    return 0;
}