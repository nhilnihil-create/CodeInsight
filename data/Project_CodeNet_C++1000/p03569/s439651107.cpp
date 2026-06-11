#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main(void){
    // Your code here!
    string s;
    cin >> s;
    
    string t;
    vector<int> counts;
    int cnt = 0;
    
    for (int i=0; i<s.size(); i++){
        if(s[i] != 'x'){
            t += s[i];
            counts.push_back(cnt);
            cnt = 0;
        }else{
            cnt++;
        }
    }
    counts.push_back(cnt);
    string t2 = t;
    reverse(t2.begin(), t2.end());
    
    if (t2 != t){
        cout << -1 << endl;
        return 0;
    }
    
    int res = 0; 
    for (int i=0; i< counts.size() / 2; i++){
        res += abs(counts[i] - counts[counts.size() - 1 - i]);
    }
    cout << res << endl;
}
