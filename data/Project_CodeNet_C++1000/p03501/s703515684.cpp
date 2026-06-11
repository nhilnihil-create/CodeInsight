#include<bits/stdc++.h>
using namespace std;
#define Yes(n) cout << ((n) ? "Yes" : "No") << endl
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define Rep(i, n,m) for (int i = (int)(n); i < (int)(m); i++)

#define ALL(V) (V).begin(),(V).end()
#define SORT(V) sort(ALL(V))

typedef long long ll;

vector<string> split(string,string);

//template<typename T>
//void swap(T*,T*);
//char ToUpper (char cX) { return toupper(cX); }

bool isR(string s);

int main()
{
    int N,A,B;
    cin >> N >> A >> B;
    cout << min(N*A,B);
}