typedef long long ll;
typedef long double LD;

#include <bits/stdc++.h>
using namespace std;
 



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, K;
    cin >> N >> K;
    N-=K;
    int sol = 0;
    if(N<=0){
        cout << "1\n";
    } else {
        sol = 1 + (N/(K-1));
        if(N%(K-1)!=0){
            sol++;
        }
        cout << sol << "\n";
    }

}
