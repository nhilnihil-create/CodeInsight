/*    Mohammed Sami Khan
                       মোহাম্মদ সামী খান
*/
#include<bits/stdc++.h>
using namespace std;
#define pi acos(-1.0)
#define mp(a,b) make_pair(a,b)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
typedef long long ll;
typedef unsigned long long ull;

bool sortbysecc(const pair<int,int> &a, const pair<int,int> &b){
    return (a.second < b.second);
}

int main()
{
    fastio;
    ll t, n, m, x=0, y=0, p, q, r, i, j, d, f=0;
    string s, a="", b="";
    cin>>s;
    for(i=0;i<s.size();i++){
        if(i%2){
            a.push_back('1');
            b.push_back('0');
        }
        else {
            a.push_back('0');
            b.push_back('1');
        }
    }
    for(i=0;i<s.size();i++){
        if(s[i]!=a[i]) x++;
        if(s[i]!=b[i]) y++;
    }
    cout<<min(x, y);
}
