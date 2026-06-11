#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin >> n;
    int l = 0;
    int r = n-1;
    string sl, sr, sm;
    cout << l << endl;
    cin >> sl;
    cout << r << endl;
    cin >> sr;
    if(sl == "Vacant" || sr == "Vacant")
        return 0;
    while(l + 1 <= r){
        int m = (l + r) / 2;
        cout << m << endl;
        cin >> sm;
        if(sm == "Vacant")
            return 0;
        else if (sm == sl){
            if((m - l) % 2 == 0){
                l = m;
                sl = sm;
            } else {
                r = m;
                sr = sm;
            }
        } else if(sm == sr){
            if((r - m) % 2 == 0){
                r = m;
                sr = sm;
            } else {
                l = m;
                sl = sm;
            }
        } else {
            if((r - m) % 2 == 0){
                l = m;
                sl = sm;
            } else {
                r = m;
                sr = sm;
            }
        }
    }
    return 0;
}