#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <iomanip>
#include <math.h>
#include <utility>

#define div1 1000000007

using namespace std;

int main(void)
{
    long long N, H, W, A[1001], B[1001], i, ans=0;

    cin >> N >> H >> W;

    for(i=1; i<=N; i++){
        cin >> A[i] >> B[i];

        if(A[i]>=H && B[i]>=W){
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}