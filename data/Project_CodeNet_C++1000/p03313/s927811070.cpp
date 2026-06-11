#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int maxN = 1 << 18;

int n;
int a[maxN][2];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(); cout.tie();

    cin >> n;

    for(int i = 0; i < 1 << n; ++i)
        cin >> a[i][0];

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < 1 << n; ++j){
            if((j & (1 << i)) == 0){
                int tmp = j | (1 << i);
                if(a[tmp][0] < a[j][0]){
                    a[tmp][1] = max(a[tmp][0], a[j][1]);
                    a[tmp][0] = a[j][0];
                }
                else
                    a[tmp][1] = max(a[tmp][1], a[j][0]);
            }
        }
    }

    int res = 0;
    for(int i = 1; i < 1 << n; ++i){
        res = max(res, a[i][0] + a[i][1]);
        cout << res << endl;
    }
}

