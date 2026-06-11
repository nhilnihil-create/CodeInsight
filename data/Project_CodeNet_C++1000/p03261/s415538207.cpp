#include<bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define ll long long
#define maxn 1000005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
#define ms1(i) memset(i,-1,sizeof(i));
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define pii pair<int,int>
const int mod = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    string last;
    cin >> last;
    set<string>st;
    st.insert(last);
    f(n-1) {
        string s;
        cin >> s;
        if (s[0] != last.back() || st.count(s)) {
            cout << "No\n";
            exit(0);
        }
        last = s;
        st.insert(s);
    }
    cout << "Yes\n";
}