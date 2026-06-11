# include<iostream>
# include<cmath>
using namespace std;

int main(void)
{
    int q;
    cin >> q;
    while(q--)
    {
        long long a, b;
        cin >> a >> b;
        long long sq = (int)sqrt(a*b);;
        long long sum = sq*2;
        if(a <= sq || b <= sq)
            sum--;
            
        if(sq*sq == a*b && a!=b)
            sum--;
        if(sq*(sq+1) >= a*b)
            sum--;

        cout << sum << endl;
    }
    return 0;
}
