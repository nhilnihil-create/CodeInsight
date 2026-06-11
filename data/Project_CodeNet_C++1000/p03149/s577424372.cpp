#include<bits/stdc++.h>

using namespace std;
using ll = long long;



int main()
{
    vector<int> a(4);
    for(int i = 0; i < 4; i++)cin >> a[i];
    sort(a.begin(), a.end());

    do{
        if(a[0] == 1 && a[1] == 9 && a[2] == 7 && a[3] == 4){cout << "YES" << endl;return 0;}
    }while(next_permutation( a.begin(), a.end()) );
    cout << "NO" << endl;


}