#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    map<int, int> memo;
    for(int i = 0; i < n; i++){
        if(memo.count(a[i])) memo[a[i]]++;
        else memo[a[i]] = 1;
    }

    int ans = 0;
    for(auto p: memo){
        if(p.first < p.second) ans += p.second-p.first;
        else if(p.first > p.second) ans += p.second;
    }
    cout << ans << endl;
    return 0;
}