#include <bits/stdc++.h>
using namespace std;
int main(){
    long ans = 0;
    string s;
    cin >> s;
    string t;
    for(int i=0;i<s.size()-1;i++){
        if(s[i]=='B'&&s[i+1]=='C'){
            t += 'T';
            i++;
        }
        else t += s[i]; 
    }
    for(int i=0;i<t.size();i++){
        int j = i;
        vector<char> m;
        while(t[j]=='A'||t[j]=='T'){
            m.push_back(t[j]);
            j++;
        }
        int numt = 0;
        for(int k=0;k<m.size();k++){
            if(m[k]=='T'){
                numt++;
                ans+=(k-numt+1);
            } 
        }
        i = j;
    }
    cout << ans << endl;
}