#include <bits/stdc++.h>

using namespace std;

#define vit vector<int>::iterator
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define fr first
#define sc second
#define skip continue
#define PI 3.14159265

typedef unsigned long long ull;
typedef long long ll;
typedef unsigned int ui;
typedef long double ld;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<bool> vb;

const int INF = 1e9 + 5;
const int MAXN = 3e6 + 123;

void faster(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
bool cmp(const string& a, const string& b) {
	return (a + b) < (b + a);
}

vector<int> Reversed(const vector<int>& s){
   vector<int> d = s;
   reverse(all(d));
   return d;
}
//int a[27];
void solve(){
    string s;
    cin >> s;
    if(((s[0] == '0' && s[1] != '0') || (s[0] == '1' && s[1] <= '2'))  && ((s[2] == '0' && s[3] != '0') || (s[2] == '1' && s[3] <= '2'))){
        cout << "AMBIGUOUS";
        return;
    }
    if(((s[0] == '0' && s[1] != '0') || (s[0] == '1' && s[1] <= '2'))  || ((s[2] == '0' && s[3] != '0') || (s[2] == '1' && s[3] <= '2'))){
       if(((s[0] == '0' && s[1] != '0') || (s[0] == '1' && s[1] <= '2')))
        cout << "MMYY";
       else cout << "YYMM   ";
    }
    else cout << "NA";
}

// ."ww"w"".ww"""...ww"".

int main(){
    //freopen("lepus.in","r",stdin);
    //freopen("lepus.out","w",stdout);
    //faster();
    int n=1;
    //cin>>n;
    while(n--){
    solve();
    //cout << endl;
    }
    //fclose(stdout);
}
