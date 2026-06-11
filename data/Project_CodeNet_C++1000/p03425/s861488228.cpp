#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int N;
    string s;
    int64_t ans = 0;
    cin >> N;

    map<char,int64_t> mp;
    for(int i=0;i<N;i++) {
        cin >> s;
        switch(s[0]) {
            case 'M':
            case 'A':
            case 'R':
            case 'C':
            case 'H':
                mp[s[0]]++;
        }
    }

    if(mp.size() < 3) {
        cout << "0\n";
        return 0;
    }
    // 5 C 3 = 10 通りを全部ためす
    
    map<char,int64_t>::iterator i,j,k,iend,jend;
    jend = mp.end();
    jend--;
    iend = jend;
    iend--;
    for(i=mp.begin();i!=iend;i++) {
        j=i;j++;
        for(;j!=jend;j++) {
            k=j;k++;
            for(;k!=mp.end();k++) {
                ans += ((i->second) * (j->second) * (k->second));
            }
        }
    }

    cout << ans << endl;
    return 0;
}
