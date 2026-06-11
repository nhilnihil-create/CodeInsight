#include "./bits/stdc++.h"

using namespace std;

#define MAX 10000

int main(){
    int n;
    cin >> n;
    int T,A;
    cin >> T >> A;
    int H[MAX];
    double diff = 1000000000;

    for(int i=0;i<n;i++){
        cin >> H[i];
    }

    int ans=0;
    double v=0.0;
    for (int i=0;i<n;i++){
        v=abs(A-T+H[i]*0.006);
        // cout << v << endl;
        if(diff > v){
            diff=v;
            ans=i;
        }
    }
    cout << ans+1 << endl;

    

    return 0;
}