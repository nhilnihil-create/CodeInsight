#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<char,int> ii;
main(){
    string s;
    cin >> s;
    stack<ii> st1,st2;
    for (int i = s.length()-1; i >= 0; i--) st2.push(ii(s[i],1));
    int num = 0;
    while (st2.size()){
        ii cur = st2.top();
        st2.pop();
        if (st1.size() && st1.top().first == cur.first && cur.first == 'A'){
            st1.top().second += cur.second;
        }
        else st1.push(cur);
        if (st1.size() < 3) continue;
        ii s = st1.top();st1.pop();
        ii f = st1.top();st1.pop();
        if (s.first == 'C' && f.first == 'B'){
            ii a = st1.top();
            if (a.first == 'A'){
                st1.pop();
                num += a.second;
                st2.push(a);
            }
        }
        st1.push(f);
        st1.push(s);

    }
    cout << num;
}
