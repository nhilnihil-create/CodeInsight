 #include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define INF 1999999999
#define MODA 1000000007

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    char a, b;
    cin >> a >> b;
    if(a > b)
        cout << ">" << endl;
    else if(a == b)
        cout << "=" << endl;
    else
       cout << "<" << endl;



    return 0;
}
