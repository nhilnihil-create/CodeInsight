#include <iostream>
#include <iomanip>
#include <string>
#include <stack>
typedef long long ll;
using namespace std;
const  ll INF = 1e9;
const  ll MOD = 1e9 + 7;
#define repi(i,n,init) for(ll i=init;i<(n);i++)

int main()
{
    string s;
    cin >> s;
    int n = s.size();
    stack<char> q;
    q.push(s[0]);
    repi(i,n,1){
        if(!q.empty() && q.top() != s.at(i))q.pop();
        else q.push(s[i]);
    }
    cout << n - q.size() << endl;
    return 0;
}