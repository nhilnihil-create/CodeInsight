#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long long unsigned int ull;
typedef long double ld;
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define INF 1999999999
#define MODA 1000000007
#define PI 3.1415926535897932384626433
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
    if(s[0] != 'A'){
        cout << "WA" << endl;
        return 0;
    }
    int countC = 0;
    for(int i = 2; i < len - 1; i++){
        if(s[i] == 'C'){
            countC++;
        }
    }
    if(countC != 1){
        cout << "WA" << endl;
        return 0;
    }
    int countA = 2;
    for(int i = 0; i < len; i++){
        if(s[i] >= 'A' && s[i] <= 'Z'){
            countA--;
        }
    }
    if(countA != 0){
        cout << "WA" << endl;
        return 0;
    }
    cout << "AC" << endl;
    return 0;
}
