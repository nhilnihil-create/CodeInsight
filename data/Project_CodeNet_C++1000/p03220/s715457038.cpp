#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
typedef  long long ll;

int main(void){
    int N,T,A;
    int index,imin = 1000000;
    cin >> N;

    cin >> T >> A;

    vector<int> H(N);

    rep(i,N)
        cin >> H.at(i);

    rep(i,N){
        int temp = 1000*T-H.at(i)*6;

        if(imin > abs(1000*A-temp)){
            index = i;
            imin = abs(1000*A-temp);
        }
        
    }

    cout << index+1 << endl;
    
    return 0;
}