typedef long long ll;
typedef long double LD;

#include <bits/stdc++.h>
using namespace std;
 



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int sol = 0;
    for(int i=0; i<4; i++){
        char c = getchar();
        if(c == '+'){
        sol++;
        } else {
        sol--;
        }
    }
    cout << sol << "\n";
    
}
