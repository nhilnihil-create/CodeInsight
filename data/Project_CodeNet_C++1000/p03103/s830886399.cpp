#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<pair<long long int, long long int>> vec(N);
    for(int i=0; i<N; i++){
        cin >> vec[i].first >> vec[i].second;
    }
    sort(vec.begin(),vec.end());


    long long int cost=0;
    long long int bought = 0;

    for(int i=0; i<N; i++){
        if(bought + vec[i].second < M){
            bought += vec[i].second;
            cost += vec[i].first * vec[i].second;
        }
        else{
            cost += vec[i].first * (M - bought);
            bought += M - bought;
            break;
        }
    }

    cout << cost << endl;
}