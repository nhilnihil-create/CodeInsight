#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int>p(N);

    for(int i=0; i<N; i++){
        cin >> p[i];
    }

    sort(p.begin(), p.end());

    int p_sum = 0;

    for(int i=0; i<N-1; i++){
        p_sum += p[i];
    }

    p_sum += p[N-1]/2;

    cout << p_sum << endl;

    return 0;
}