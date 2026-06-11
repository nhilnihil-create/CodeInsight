#include <iostream>
using namespace std;
int main() {
    int N, K; cin>>N>>K;
    N-K >= K-1 ? cout<<"YES"<<endl : cout<<"NO"<<endl;
    return 0;
}
