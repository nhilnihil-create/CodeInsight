#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define f first
#define s second
using namespace std;
string a, b;
ll freqa[28], freqb[28];
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> a >> b;
    for(int i = 0; i < a.length(); i++){
        freqb[b[i]-'a']++;
        freqa[a[i]-'a']++;
    }
    bool ok = 1;
    sort(freqa, freqa+26); sort(freqb, freqb+26);
    for(int i = 0; i < 26; i++){
        if(freqa[i] == freqb[i])continue;
        else{
            cout << "No" << endl; return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}
