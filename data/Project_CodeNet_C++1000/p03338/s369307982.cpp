#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n;
    string s;
    cin >> n >> s;
    int cnt,maxcnt = 0;

    map<int,int> mpb,mpa;
    for(int i=1;i<s.size()-1;i++) {
        mpb.clear();
        mpa.clear();
        for(int j=0;j<i;j++) {
            mpb[s[j]]++;
        }
        for(int k=i;k<s.size();k++) {
            mpa[s[k]]++;
        }

        cnt = 0;
        for(auto b:mpb) {
            for(auto a:mpa) {
                if(b.first == a.first) {
                    cnt++;
                    break;
                }
            }
        }

        if(maxcnt < cnt) {
            maxcnt = cnt;
        }
    }

    cout << maxcnt << endl;
    return 0;
}
