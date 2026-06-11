#include<bits/stdc++.h>
using namespace std;
#define int long long
//#undef int
#define mk make_pair
#define pb push_back
#define pf push_front
typedef pair<int, int> pii;
const int mod = 1000000007;
const int INF = 1000000009;
const long long INFL = 1000000000000000018ll;

string s;
int a, b, c;
vector<int> v;

signed main()
{
    cin >> s;
    int N = s.size();
    for(int i = 0; i < N; i++){
        if(s[i] == 'a'){
            a++;
        }
        else if(s[i] == 'b'){
            b++;
        }
        else {
            c++;
        }
    }
    v.pb(a);
    v.pb(b);
    v.pb(c);
    sort(v.begin(), v.end());
    if(v[0] == v[1] && v[1] == v[2] || v[0] == v[1] && v[1] == v[2] - 1 || v[0] + 1 == v[1] && v[1] == v[2]){
        printf("YES\n");
    }
    else {
        printf("NO\n");
    }


    return 0;
}
/*


*/


