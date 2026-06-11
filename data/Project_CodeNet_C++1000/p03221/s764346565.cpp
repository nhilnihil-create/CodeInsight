#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

int main(){
    long long n, m;
    cin >> n >> m;

    vector<long long>Pref(m), Year(m);
    vector<vector<long long> > pref_year(n+1);

    for(long long i = 0; i < m; i++){
        cin >> Pref[i] >> Year[i];
        pref_year[Pref[i]].push_back(Year[i]);
    }

    map<long long, long long> year_rank;
    for(long long i = 0; i <= n; i++){
        sort(pref_year[i].begin(), pref_year[i].end());
        for(long long j = 0; j < pref_year[i].size(); j++){
            year_rank[pref_year[i][j]] = j+1;
        }
    }

    for(long long i = 0; i < m; i++){
        //printf("year_rank[Year[i]] %lld\n", year_rank[Year[i]]);
        printf("%06lld%06lld\n", Pref[i], year_rank[Year[i]]);
    }

    return 0;
}