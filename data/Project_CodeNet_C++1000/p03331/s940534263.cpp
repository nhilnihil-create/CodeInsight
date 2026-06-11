#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i,n) for (int (i)=0; (i) < (n); (i)++)

ll func(ll num)
{
        ll sum = 0;
        ll s = num;
        vector<ll> v;
        while (1) {
                ll amari = s % 10;
                v.push_back(amari);
                sum += amari;
                s /= 10;
                if (s == 0) break;
        }
        return sum;
}

int main()
{
        ll N;
        cin >> N;

        ll ans = 0;
        ll A, B;
        ll min = 0;
        for (int i = 1; i < N; ++i) {
                A = i;
                B = N - i;
                ll tmp = func(A) + func(B);
//              cout << "A = " << A << ",B = " << B << ",tmp= " << tmp << endl;
                if (i == 1) {
                        min = tmp;
                }
                else if (min > tmp) {
                        min = tmp;
                }


        }

        cout << min << endl;

}
