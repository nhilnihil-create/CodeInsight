#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main(){
    long long n, m;
    cin >> n >> m;

    vector<long long> food(m, 0);

    for(long long i = 0; i < n; i++){
        long long k;
        cin >> k;
        for(long long j = 0; j < k; j++){
            long long a;
            cin >> a;
            food[a-1]++;
        }
    }

    long long count = 0;

    for(long long i = 0; i < m; i++){
        if(food[i] == n){
            count++;
        }
    }

    cout << count << endl;
    return 0;
}
