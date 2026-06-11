#include <iostream>

using namespace std;

int main(void)
{
    long long N, A, B, P[101], i, count1=0, count2=0, count3=0, ans;

    cin >> N;
    cin >> A >> B;

    for(i=1; i<=N; i++){
        cin >> P[i];
        if(P[i] <= A){
            count1++;
        }
        else if(P[i]>=B+1){
            count3++;
        }
        else{
            count2++;
        }
    }

    ans = count1;

    if(ans > count2){
        ans = count2;
    }

    if(ans > count3){
        ans = count3;
    }

    cout << ans << endl;

    return 0;
}