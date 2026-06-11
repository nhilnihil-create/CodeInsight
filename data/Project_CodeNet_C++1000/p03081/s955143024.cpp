#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

int n, q;
char s[200010];
char t[200010];
char d[200010];
int nl, nr, ans;

int endState(const char s[], const char t[], const char d[], int n, int q, int p){
    // 0: left
    // 1: middle
    // 2: right
    for (int i = 0; i < q; ++i){
        if (s[p] == t[i]){
            if (d[i] == 'L') p--;
            else p++;
            if (p == -1) return 0;
            if (p == n) return 2;
        }
    }
    return 1;
}

int binarySearch(const char s[], const char t[], const char d[], int n, int q, int key, int imin, int imax){
    // key: end state
    if (imax < imin) return -1;
    else{
        int imid = imin + (imax - imin) / 2;
        int smid = endState(s, t, d, n, q, imid);
        if (smid > key){
            return binarySearch(s, t, d, n, q, key, imin, imid - 1);
        }
        else if (smid < key){
            return binarySearch(s, t, d, n, q, key, imid + 1, imax);
        }
        else{
            int snext = endState(s, t, d, n, q, imid+(1-key));
            if (snext != smid){
                return imid;
            }
            else{
                if (key == 0){
                    return binarySearch(s, t, d, n, q, key, imid + 1, imax);
                }
                else{
                    return binarySearch(s, t, d, n, q, key, imin, imid - 1);
                } 
            }
        }
    }
}

int main(){
    cin >> n >> q;
    cin >> s;

    for (int i = 0; i < q; ++i){
        cin >> t[i] >> d[i];
    }

    if (n == 1) cout << (endState(s, t, d, n, q, 0) == 1);
    else if (n == 2) cout << ((endState(s, t, d, n, q, 0) == 1) + (endState(s, t, d, n, q, 1) == 1));
    else{
        nl = binarySearch(s, t, d, n, q, 0, 0, n-1);
        nl = (nl >= 0) ? nl + 1 : 0;
        nr = binarySearch(s, t, d, n, q, 2, 0, n-1);
        nr = (nr >= 0) ? n - nr : 0;
        ans = n - (nl + nr);
        cout << ans;
    }
}