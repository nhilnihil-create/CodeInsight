 #include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long long unsigned int ull;
typedef long double ld;
typedef vector<int> vr;
typedef pair<int, int> pr;
#define pb push_back
#define ff first
#define ss second
#define INF 1999999999
#define MODA 1000000007
#define PI 3.1415926535897932384626433
#define endl "\n"
//cout << fixed << setprecision(2);

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin >> s;
    int len = s.size();
    //cout << len << endl;
    string ke = "keyence";
    int j = 0;
    for(int i = 0; i <= 7; i++){
        //cout << s.substr(0, i) << " = " <<  s.substr(s.size()-7+i) << endl;
        if(s.substr(0, i) + s.substr(len-7+i) == ke){
           cout << "YES" << endl;
           return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}

