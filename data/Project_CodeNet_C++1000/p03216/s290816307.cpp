#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    int n,q;
    string s;
    cin >> n >> s >> q;


    for (int i=0; i<q; i++) {
        int k;
        cin >> k;

        long ans = 0;
        long r = 0;
        long d = 0;
        long m = 0;
        long dm = 0;
        for (int l=0; l<n; l++) {
            if (r<l) r = l;
            while(r<n && r-l<k) {
                if (s[r] == 'D') d++;
                if (s[r] == 'M') m++,dm+=d;
                if (s[r] == 'C') ans += dm;
                r++;
            }
            if (s[l] == 'D') d--,dm-=m;
            if (s[l] == 'M') m--;
        }
        cout << ans << endl;
    }
}
