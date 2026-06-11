#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <deque>
#include <queue>

using namespace std;
typedef long long ll;

ll A[100005];
ll L[100005], R[100005];
ll l,r;

int main(){
    int K;
    cin >> K;
    for(int i = 1; i <= K; i++) cin >> A[i];

    L[K] = 2; R[K] = 2;
    
    for(int i = K; i >= 1; i--){
        if(L[i]%A[i]==0||R[i]%A[i]==0||R[i]-L[i]+(L[i]%A[i])>=A[i]){
            if(L[i]%A[i] == 0) l = L[i]/A[i];
            else l = L[i]/A[i]+1;
            r = R[i]/A[i];
            L[i-1] = l*A[i];
            R[i-1] = r*A[i]+A[i]-1;
        } else {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << L[0] << " " << R[0] << endl;
}

