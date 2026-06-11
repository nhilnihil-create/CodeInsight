#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using P = pair<int, int>;
int main()
{
    int n;
    cin >> n;
    int nn = n;
    int cnt= 0;
    while(n > 0){
        cnt += n%10;
        n /= 10;
    }
    if(nn % cnt == 0)cout << "Yes" << endl;
    else cout << "No" << endl;
return 0;
}