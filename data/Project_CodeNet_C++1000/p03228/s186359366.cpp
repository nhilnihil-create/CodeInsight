#include <iostream>

using namespace std;
typedef long long ll;

#define REP(i,n) for(int i = 0; i < n; i++)

int main(void)
{
    int A[2],K,p,q;
    cin >> A[0] >> A[1] >> K;
    for(int i = 0; i < K; i++) {
        p=i%2;q=1-p;
        if(A[p]%2==1) {
            A[p]-=1;
        }
        A[q]+=A[p]/2;
        A[p]/=2;
    }

    cout << A[0] << " " << A[1] << endl;


}
