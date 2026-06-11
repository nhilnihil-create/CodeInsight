#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

bool compair(pair<long long, long long> a, pair<long long, long long> b){
    return a.second > b.second;
}

int main(){
    long long n, m;
    cin >> n >> m;

    vector<long long> a(n);

    for(long long i = 0; i < n; i++){
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    vector<pair<long long, long long> > bc(m);

    for(long long i = 0; i < m; i++){
        cin >> bc[i].first >> bc[i].second;
    }

    sort(bc.begin(), bc.end(), compair);

    long long sum = 0;

    vector<long long> b(n, 0);

    long long b_index = 0;
    for(long long i = 0; i < m; i++){
        if(b_index >= n){
            break;
        }
        for(long long j = 0; j < bc[i].first; j++){
            if(b_index >= n){
                break;
            }
            b[b_index] = bc[i].second;
            b_index++;
        }
    }

    for(long long i = 0; i < n; i++){
        sum += max(a[i], b[i]);
    }

    cout << sum << endl;
    return 0;

}