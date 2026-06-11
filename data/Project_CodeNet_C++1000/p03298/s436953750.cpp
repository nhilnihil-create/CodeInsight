#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
using namespace std;

typedef pair<string, string> P;

int main(){
    int N;
    cin >> N;
    string s;
    cin >> s;

    string s1 = s.substr(0, N);
    string s2 = s.substr(N, N);
    reverse(s2.begin(), s2.end());

    //cout << s1 << " " << s2 << endl;

    map<P, ll> mp;

    //s1
    for(int msk = 0; msk < (1 << N); msk++){
        string red = "";
        string blue = "";
        for(int i = 0; i < N; i++){
            if(msk & (1 << i)){
                red += s1[i];
            } else {
                blue += s1[i];
            }
        }

        mp[P(red, blue)]++;
    }

    ll ans = 0;

    //s2
    for(int msk = 0; msk < (1 << N); msk++){
        string red = "";
        string blue = "";
        for(int i = 0; i < N; i++){
            if(msk & (1 << i)){
                red += s2[i];
            } else {
                blue += s2[i];
            }
        }

        ans += mp[P(red, blue)];
    }

    cout << ans << endl;
    return 0;
}
