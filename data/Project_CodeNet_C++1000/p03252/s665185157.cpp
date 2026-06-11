#include <bits/stdc++.h>

#define fast                     \
    ios::sync_with_stdio(false); \
    cin.tie(NULL);               \
    cout.tie(NULL)
#define int long long
#define endl '\n'
#define all(a)                   (a).begin(),(a).end()

#define Unique(A)                (A).resize(distance((A).begin(),unique(all((A)))))

using namespace std;

const int N = 2e5 + 77;

string a , b ;
int n ; 
int A[N] , B[N];

int32_t main()
{
    fast;
    cin >> a >> b;
    n = a.length();
    bool ok = true;
    for(int i = 0 ; i < n ; ++i){
        int x = a[i]-'a' , y = b[i]-'a';
        A[x]++;B[y]++;
        if(A[x]!=B[y]){
            ok = false;
            break;
        }
    }
    
    if(ok) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}