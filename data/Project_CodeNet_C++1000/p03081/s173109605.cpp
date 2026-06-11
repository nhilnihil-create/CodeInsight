#include <iostream>
using namespace std;

int main()
{
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    char t[200005], d[200005];
    for(int i = 0; i < q; i++) cin >> t[i] >> d[i];
    int left = 0, right = n + 1;
    while(right - left > 1){
        int mid = (right + left) / 2;
        int p = mid;
        bool f = false;
        for(int i = 0; i < q; i++){
            if(s[p - 1] == t[i]){
                if(d[i] == 'L') p--;
                else p++;
            }
            if(p <= 0) f = true;
        }
        if(f) left = mid;
        else right = mid;
    }
    int l = left;
    left = 0, right = n + 1;
    while(right - left > 1){
        int mid = (right + left) / 2;
        int p = mid;
        bool f = false;
        for(int i = 0; i < q; i++){
            if(s[p - 1] == t[i]){
                if(d[i] == 'L') p--;
                else p++;
            }
            if(p > n) f = true;
        }
        if(f) right = mid;
        else left = mid;
    }
    int r = right;
    cout << max(0, n - l - (n + 1 - r)) << endl;
}
