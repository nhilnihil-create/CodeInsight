#include <iostream>
using namespace std;
int main() {
    int D, N; cin>>D>>N;
    int div=0;
    D == 0 ? div=1 : D == 1 ? div=100 : div=10000;
    N < 100 ? cout<<N*div<<endl : cout<<101*div<<endl;
    return 0;
}
