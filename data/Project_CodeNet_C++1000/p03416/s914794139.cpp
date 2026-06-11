#include <iostream>

#define endl '\n'
#define pb push_back
#define F first
#define S second
typedef long long ll;
typedef unsigned long long ull;

using namespace std;

void solve()
{
    int a, b;

    cin >> a >> b;

    int pal = 0;

    for(int i = a; i <= b; i++)
    {
        string s;
        int temp = i, sz = 0;
        while(temp != 0)
        {
            s.pb(temp%10 + 48);
            temp /= 10;
            ++sz;
        }
        int half = sz/2;
        bool palindrome = true;
        for(int j = 0; j < half; j++)
        {
            if(s[j] != s[sz-j-1])
            {
                palindrome = false;
                break;
            }
        }
        if(palindrome)
            pal++;
    }

    cout << pal;


}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

//    int t; cin >> t; while(t--){
        solve();
//    }
    return 0;
}
