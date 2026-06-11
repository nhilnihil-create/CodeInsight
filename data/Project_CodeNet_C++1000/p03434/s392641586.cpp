#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
typedef  long long ll;

int main(void){
    int alice = 0,bob = 0;
    int N;
   

    cin >> N;
    vector<int> A(N);

    rep(i,N)
    cin >> A.at(i);

    sort(A.begin(),A.end());
    reverse(A.begin(),A.end());

    rep(i,N){
        if(i%2 == 0)
        alice += A[i];

        else
        bob += A[i];
        
    }

    cout << alice-bob << endl;

    return 0;
}