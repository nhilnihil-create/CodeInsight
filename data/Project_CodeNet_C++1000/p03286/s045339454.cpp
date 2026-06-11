#include <bits/stdc++.h>
using namespace std;

signed main()
{
    long long n , r = 1 , two = 2;
    stack<int> s;

    cin >> n;

    if(n == 0){
        cout << "0\n";
    } else {
        while(n != 0){
            if(n % two != 0){
                n-=r;
                s.push(1);
            } else {
                s.push(0);
            }
            r = r * -2;
            two = two * 2;
        }

        while( !(s.empty()) ){
            cout << s.top();
            s.pop();
        }
        cout << endl;
    }

    return (0);
}