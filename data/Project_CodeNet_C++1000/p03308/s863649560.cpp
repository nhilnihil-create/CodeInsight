#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N; cin>>N;
    vector<long long> v(N, 0);
    for (int i=0; i<N; i++) cin>>v.at(i);
    sort(v.begin(), v.end());
    cout<<v.at(N-1)-v.at(0)<<endl;
    return 0;
}
