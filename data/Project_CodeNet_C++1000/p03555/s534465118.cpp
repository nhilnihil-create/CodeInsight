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
    string s,t;
    cin >> s;
    cin >> t;
    if(s[0] == t[2] && s[1] == t[1] && s[2] == t[0])
    {
        cout << "YES";
    }else
    {
        cout << "NO";
    }
}
