#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N,M;
    cin >> N >> M;
    int sum = 1900*M + 100*(N - M);
    int power = 1; for(int i = 0; i < M; ++i) power *= 2;
    cout << sum*power << endl;
    return 0;
}
