#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
typedef long long ll;


int main(void)
{

    int A,B,tmp,a,b,d,e,cnt = 0;

    cin >> A >> B;

    for(int i = A;i <= B;i++){
        tmp = i;
        a = tmp%10;
        b = (tmp /= 10)%10;
        tmp /= 10;
        d = (tmp /= 10)%10;
        e = (tmp /= 10)%10;

        if(a == e && b== d)
            cnt++;
    }

    cout << cnt << endl;

    return 0;
}