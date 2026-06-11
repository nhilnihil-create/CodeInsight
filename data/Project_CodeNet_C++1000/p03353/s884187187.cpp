#include<bits/stdc++.h>
using namespace std;
#define ll  long long
#define endl '\n'
#define FASTINOUT ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const ll mod = 1000000007;
const double PI = 3.141592653589793238463;
const int N=1e5+9;
int main()
{
    FASTINOUT;
    string s;
    cin>>s;
    int k;
    cin>>k;
    int ls=s.length();
    set<string>st;
    for (int i=0;i<ls;i++){
        for (int j=1;j<=k;j++){
            st.insert(s.substr(i,j));
        }
    }
    for (auto i:st){
     k--;
     if (k==0)
            cout<<i<<endl;
    }
    return 0;
}
