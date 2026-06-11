#include <bits/stdc++.h>
#define INF 1e9
#define MOD 1000000007
using namespace std;
using ll = long long;
using pii = pair<int, int>;
 
int main(void) {
    string sdash, t;
    cin >> sdash;
    cin >> t;
 
    vector<string> strSet;
 
    int slen = sdash.size();
    int tlen = t.size();
 
    for (int j = 0; j <= slen - tlen; j++)
    {
        string s = sdash;
        bool match = true;
        for (int i = 0; i < tlen; i++)
        {
            if(s[j+i] != t[i]){
                if(s[j+i] == '?'){
                    s[j+i] = t[i];
                } else {
                    match = false;
                    break;
                }
            }
        }
        if(match) {
            for (int i = 0; i < slen; i++)
            {
                if(s[i] == '?') s[i] = 'a';
            }
            strSet.push_back(s);
        }
    }
 
    if(strSet.empty()){
        cout << "UNRESTORABLE" << endl;
    } else {
        sort(strSet.begin(), strSet.end());
        cout << *strSet.begin() << endl;
    }
    return 0;
}