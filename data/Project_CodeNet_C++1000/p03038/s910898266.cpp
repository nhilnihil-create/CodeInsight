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

    vector<long long> b;

    for(long long i = 0; i < n; i++){
        if(a[i] < bc[0].second){
            b.push_back(a[i]);
        }
        else{
            sum += a[i];
        }
    }

    vector<long long>::iterator it;
    for(long long i = 0; i < m; i++){
        

        long long count = 0;
        for(it = b.begin(); it != b.end();){
            if(count >= bc[i].first){
                break;
            }

            if(*it < bc[i].second){
                sum += bc[i].second;
                it = b.erase(it);
            }
            else{
                it++;
            }
            count++;
        }
    }

    for(long long i = 0; i < b.size(); i++){
        sum += b[i];
    }

    cout << sum << endl;

    return 0;
}