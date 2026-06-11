#include <bits/stdc++.h> 

using namespace std;

#define YES cout << "YES" << endl;
#define NO  cout << "NO"  << endl;
#define Yes cout << "Yes" << endl;
#define No  cout << "No"  << endl;
 
#define INF INT_MAX
#define MOD 1000000007
#define PI  acos(-1)

using ll  = long long;
using ull = unsigned long long;
using Pii = pair<int, int>;
using Pll = pair<ll, ll>;

#define rep(i, n) for (ll i = 0; i < (n); i++)
#define rrep(i, n) for (ll i = (n)-1; i >= 0; i--)

int main(int argc, char *argv[])
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    string S;
    cin >> S;

    bool flag = false;
    if (S == "KIHBR") {
        flag = true;
    } else if (S == "KIHBRA") {
        flag = true;
    } else if (S == "KIHBAR") {
        flag = true;
    } else if (S == "KIHBARA") {
        flag = true;
    } else if (S == "KIHABR") {
        flag = true;
    } else if (S == "KIHABRA") {
        flag = true;
    } else if (S == "KIHABAR") {
        flag = true;
    } else if (S == "KIHABARA") {
        flag = true;
    } else if (S == "AKIHBR") {
        flag = true;
    } else if (S == "AKIHBRA") {
        flag = true;
    } else if (S == "AKIHBAR") {
        flag = true;
    } else if (S == "AKIHBARA") {
        flag = true;
    } else if (S == "AKIHABR") {
        flag = true;
    } else if (S == "AKIHABRA") {
        flag = true;
    } else if (S == "AKIHABAR") {
        flag = true;
    } else if (S == "AKIHABARA") {
        flag = true;
    }

    if (flag) {
        YES;
    } else {
        NO;
    }
    return 0;
}