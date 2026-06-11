#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define PB push_back
#define PII pair <long long , long long>
#define FAST ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int MAXN = 2e5 + 10 , INF = 1e9;

int main() {
    int n;
    cin >> n;
    int l = 1 , r = n + 1;
    cout << l - 1 << endl;
    string s , s2;
    cin >> s;
    if(s == "Vacant") {
        return 0;
    }
    while(1) {
        int mid = (r + l) / 2;
        cout << mid - 1 << endl;
        cin >> s2;
        int dis = mid - l - 1;
        if(s2 == "Vacant") {
            return 0;
        }
        else if(s2 == s) {
            if(dis % 2 == 0) {
                r = mid;
            }
            else {
                l = mid;
                s = s2;
            }
        }
        else {
            if(dis % 2) {
                r = mid;
            }
            else {
                l = mid;
                s = s2;
            }
        }
    } 
}
