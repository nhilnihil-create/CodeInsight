#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;


int main(){
    long long n, m;
    cin >> n >> m;

    vector<pair<long long, long long> > v;

    for(long long i = 0; i < n; i++){
        long long a, b;
        cin >> a >> b;
        v.push_back(make_pair(a, b));
    }

    sort(v.begin(), v.end());

    long long sum = 0;
    long long cost = 0;
    long long i = 0;
    while(1){
        if(sum + v[i].second < m){
            sum += v[i].second;
            cost += v[i].first*v[i].second;
            i++;
        }
        else if(sum + v[i].second >= m){
            cost += (m - sum)*v[i].first;
            sum = m;
            break;
        }
    }

    cout << cost << endl;

    return 0;
}