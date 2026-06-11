//  ©   ___MRX___

#include <bits/stdc++.h>
    using namespace std;

#define ll long long int

int main()
{

    int a, b, rev_number, i, count = 0, temp;
    cin >> a >> b;

    for(i = a; i <= b; i++) {
        temp = i;
        rev_number = 0;
        while(temp) {
            rev_number = rev_number * 10 + temp % 10;
            temp /= 10;
        }
        if(i == rev_number) count++;
    }

    cout << count << '\n';

    return 0;
}
