//                                 Alisher_2211
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        # include <bits/stdc++.h>
# define  long          long long
# define  all(vc)       vc.begin(),vc.end()
# define  allr(vc)      vc.rbegin(),vc.rend()
# define  pb            push_back
# define  fi            first 
# define  se            second
# define  pi            pair <long, long>    
# define  lcm(a, b)     (a * b) / __gcd(a, b)
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        using namespace std;
const long N = 100100;
void read(){freopen("input.txt" , "r" , stdin );freopen("output.txt", "w" , stdout );}
long dp[N][2];
string s;
void solve(){
    cin >> s;
    long a = s[0] - '0', b = s[1] - '0', c = s[2] - '0', d = s[3] - '0';
    if( a - b - c - d == 7 ) cout << a << "-" << b << "-" << c << "-" << d << "=7";
    else if( a - b - c + d == 7 ) cout << a << "-" << b << "-" << c << "+" << d << "=7";
    else if( a - b + c - d == 7 ) cout << a << "-" << b << "+" << c << "-" << d << "=7";
    else if( a - b + c + d == 7 ) cout << a << "-" << b << "+" << c << "+" << d << "=7";
    else if( a + b + c + d == 7 ) cout << a << "+" << b << "+" << c << "+" << d << "=7";
    else if( a + b + c - d == 7 ) cout << a << "+" << b << "+" << c << "-" << d << "=7";
    else if( a + b - c + d == 7 ) cout << a << "+" << b << "-" << c << "+" << d << "=7";
    else if( a + b - c - d == 7 ) cout << a << "+" << b << "-" << c << "-" << d << "=7";
}
int32_t main(){
ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); 
        long T = 1;
        //cin >> T;
        while( T-- ){
            solve();
            cout<<'\n';
        }
cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
}