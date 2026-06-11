#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cctype>
#include <functional>
using namespace std;
using ll = long long;

#define reps(i,s,n) for(int (i) = (s); (i) < (n); (i)++)
#define rep(i,n) reps(i,0,n)


int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    rep(i,n)cin >> v[i];

    sort(v.begin(),v.end());
    int tmp = v[0];
    int cnt = 1;
    reps(i,1,n){
        if(tmp != v[i]) {
            tmp = v[i];
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}