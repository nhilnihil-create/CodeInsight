#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int q;
    cin >> q;
    for(int c = 0; c < q; c++){
        int k;
        cin >> k;
        ll a = 0, b = 0, r = 0, ans = 0;
        for(int i = 0; i < n; i++){
            if(i >= k){
                if(s[i - k] == 'D'){
                    a--;
                    r -= b;
                }
                if(s[i - k] == 'M') b--;
            }
            if(s[i] == 'D') a++;
            if(s[i] == 'M'){
                b++;
                r += a;
            }
            if(s[i] == 'C') ans += r;
        }
        cout << ans << endl;
    }
}