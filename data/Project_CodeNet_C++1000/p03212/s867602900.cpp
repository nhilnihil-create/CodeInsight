#include <bits/stdc++.h>
using namespace std;

int n;

int solve(long long x){
    if(n < x) return 0;
    int res = 0;

    res += solve(x * 10 + 3);
    res += solve(x * 10 + 5);
    res += solve(x * 10 + 7);

    set<int> s;
    while(x > 0){
        s.emplace(x%10);
        x /= 10;
    }
    if(s.size() == 3) res++;
    return res;
}

int main(){
    cin >> n;
    cout << solve(0) << endl;
}