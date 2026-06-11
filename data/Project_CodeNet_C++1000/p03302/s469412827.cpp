/**
 *      purpose : SoundHound Inc. Programming Contest 2018 -Masters Tournament- A
 *      author  : kyomukyomupurin
 *      created : 2018-10-25 23:58:59
**/

#include <bits/stdc++.h>
using namespace std;
#define int64 long long
#define print(x) cout << (x) << '\n'

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int a, b; cin >> a >> b;
    if (a + b == 15) print('+');
    else if (a * b == 15) print('*');
    else print('x');
    
    return 0;
}