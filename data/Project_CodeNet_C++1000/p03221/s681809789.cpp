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

vector<int> P[N];
int A[N],B[N];
map<int,string> M;

string Make(int n){
    string s = to_string(n);
    int x = 6-s.length();
    s = string(x,'0') + s;
    return s;
}

int32_t main()
{
    fast;
    int n , m ;cin >> n >> m ;
    for(int i = 0 ; i < m ; ++i){
        int a , b ; cin >> a >> b;
        P[a].push_back(b);
        A[i] = a;
        B[i] = b;
    }

    for(int i=1;i<=n;++i){
        sort(P[i].begin(),P[i].end());
        for(int j = 0 ; j < P[i].size() ; ++j){
            string s = Make(j+1);
            M[P[i][j]] = s;
        }
    }

    for(int i = 0 ;  i < m ; ++i){
        cout << Make(A[i]) << M[B[i]] << endl;
    }
    return 0;
}