#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b)      for(int i=a;i<=b;i++)
#define revp(i,b,a)     for(int i=b;i>=a;i--)

int n;
string s;
set<string> a;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    

    set<string> a;
    cin >> n;
    bool flag = true;
    string last = "";
    rep(i,1,n) 
    {
        cin >> s;
        if (a.count(s)) 
        {
            flag = false;
        } 
        else 
        {
            a.insert(s);
            if (last.empty() || last.back() == s.front()) 
            {
 
            } 
            else
                flag = false;
        }
        last = s;
    }
 
    if(flag)
        cout<<"Yes";
    else
        cout<<"No";
}

