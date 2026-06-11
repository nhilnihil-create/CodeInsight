#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>
#include <queue>
#include <string>

#define reps(i,s,n) for(int (i) = (s); (i) < (n); (i)++)
#define rep(i,n) reps(i,0,n)
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using vi = vector<int> ;
using vl = vector<ll>;

int main(){
    string s;
    cin >> s;
    ll cnt = 0;
    int w_count = 0;
    rep(i,s.length()){
        if(s[i] == 'W'){ 
            w_count++;
            //cout << i << " " << w_count << endl;
            cnt += (i+1-w_count);
        }
    }

    cout << cnt << endl;
    return 0;
}