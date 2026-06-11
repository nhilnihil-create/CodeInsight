#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fast ios_base::sync_with_stdio(false) , cin.tie(0) ;
#define all(v) v.begin(),v.end()
#define w(x) cout << (#x) << " is " << x << "\n" ;

int main()
{
    fast ;
    int n,t,i;
    char c ;
    cin >> c ;
    if(c=='A')
        cout << "T\n";
    else if(c=='T')
        cout << "A\n";
    else if(c=='G')
        cout << "C\n";
    else if(c=='C')
        cout << "G\n";

    return 0;
}
