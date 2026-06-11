#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
// #include <cmath>
// #include <math.h>
using namespace std;

int main(){
    int N, K;
    cin >> N >> K;
    int a;
    vector<int> v(N+10, 0);
    for(int i=0; i<N; ++i){
        cin >> a;
        v[a] += 1;
    }
    sort(v.begin(), v.end(), greater<int>());
    int sum = 0;
    for(int i=K; i<=N; ++i){
        sum += v[i];
    }
    cout << sum << endl;
}