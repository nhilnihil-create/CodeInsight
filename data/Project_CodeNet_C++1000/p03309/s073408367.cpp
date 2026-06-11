#include <iostream>
#include <algorithm>

using namespace std;

const long MOD = 1000000007;
typedef pair<int, int> P;
typedef long long ll;

int main(){
    int N;
    cin >> N;

    int A[N];
    for(int i=0; i<N; i++){
        cin >> A[i];
        A[i] = A[i] - (i+1);
    }

    sort(A, A+N);
    int b = (N+1)/2 - 1 ;

    ll ans = 0;
    for(int i=0; i<N; i++){
        ans = ans + abs(A[i] - A[b]);
    }

    cout << ans << endl;

    return 0;
}
