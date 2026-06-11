#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pii pair<int , int>
#define _FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MAXX 1005

int n , k;

int main()
{
    _FastIO;
    cin >> n;
    vector<bool> used(300 , false);
    for(int i = 0; i <= 25; i++){
        for(int j = 0; j <= 25; j++){
            used[i * 4 + j * 7] = true;
        }
    }
    if(used[n]){
        cout << "Yes" << endl;
    }
    else
        cout << "No" << endl;
    return 0;
}
