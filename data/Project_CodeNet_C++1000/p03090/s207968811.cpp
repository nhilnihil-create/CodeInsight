#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main(){
    long long n;
    cin >> n;

    vector<pair<long long, long long> > res;

    long long dame = n;
    if(n % 2 == 1) dame--;

    for(long long i = 1; i <= n; i++){
        for(long long j = 1; j <= n; j++){
            if(j <= i || j == dame) continue;
            res.push_back(make_pair(i, j));
        }
        dame--;
    }

    cout << res.size() << endl;
    for(auto p : res){
        cout << p.first << " " << p.second << endl;
    }
    return 0;
}