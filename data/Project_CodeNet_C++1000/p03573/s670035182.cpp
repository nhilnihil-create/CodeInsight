#include<bits/stdc++.h>
using namespace std;
#define Yes(n) cout << ((n) ? "Yes" : "No") << endl
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(V) (V).begin(),(V).end()
#define SORT(V) sort(ALL(V))

vector<string> split(string,string);

//template<typename T>
//void swap(T*,T*);
//char ToUpper (char cX) { return toupper(cX); }

int main()
{
    int A,B,C;
    cin >> A >> B >> C;
    if(A==B)
    {
        cout << C;
    }
    else if(A == C)
    {
        cout << B;
    }
    else
    {
        cout << A;
    }
}
