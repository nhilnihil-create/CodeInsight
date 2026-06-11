#include <bits/stdc++.h>
using namespace std;
#define Hello ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define endl '\n'
int main()
{
    Hello
    string s, t;
    cin >> s >> t;
    if(s == t)
        return cout << "Yes", 0;
    for(int i = 0; i < s.size(); i++){
        char temp = s.back();
        s.pop_back();
        s = temp + s;
       // cout << s << endl;
        if(s == t)
            return cout << "Yes", 0;
    }
    cout << "No";
    return 0;
}