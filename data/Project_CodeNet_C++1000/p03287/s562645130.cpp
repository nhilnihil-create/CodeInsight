#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    int Ai;
    int sum = 0;
    map<int, int> counts;
    counts[0] = 1;
    for(int i=0;i<N;i++){
        cin >> Ai; 
        sum = (sum + Ai) % M;
        if(counts.count(sum)==0) counts[sum] = 0;
        counts[sum]++;
    }
    long long res = 0;
    for(auto m : counts){
        res += (long long)m.second * (m.second - 1) / 2;
    }
    cout << res << endl;

    return 0;
}