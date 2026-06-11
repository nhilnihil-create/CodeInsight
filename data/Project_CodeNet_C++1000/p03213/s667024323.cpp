//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
using namespace std;
using ll = int64_t;
using vi = vector<int>;
using vvi = vector<vi>;


int main() {
    set<int> prime;
    prime.insert(2);
    prime.insert(3);
    prime.insert(5);
    prime.insert(7);
    prime.insert(11);
    prime.insert(13);
    prime.insert(17);
    prime.insert(19);
    prime.insert(23);
    prime.insert(29);
    prime.insert(31);
    prime.insert(37);
    prime.insert(41);
    prime.insert(43);
    prime.insert(47);

    int n;
    cin >> n;

    vi yy(5);
    for(int x:prime) {
        int i=0;
        int n_ = n;
        while(n_) {
            i += n_/x;
            n_ /= x;
        }
        if(i >= 2) {
            yy[0]++;
        }
        if(i >= 4) {
            yy[1]++;
        }
        if(i >= 14) {
            yy[2]++;
        }
        if(i >= 24) {
            yy[3]++;
        }
        if(i >= 74) {
            yy[4]++;
        }
    }

    int ans=0;
    ans += (yy[0]-2)*(yy[1]*(yy[1]-1)/2);
    ans += (yy[0]-1)*yy[3];
    ans += (yy[1]-1)*yy[2];
    ans += yy[4];

    //cout << yy[0] << yy[1] << yy[2] << yy[3] << yy[4] << endl;

    cout << ans << endl;

}