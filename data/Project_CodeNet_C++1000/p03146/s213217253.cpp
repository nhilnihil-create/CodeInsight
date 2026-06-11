#include<bits/stdc++.h>
using namespace std;
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);
#define file() freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const long long int infLL = 9000000000000000000;
#define mem(a,b) memset(a, b, sizeof(a) )
#define all(a) (a).begin(),(a).end()
#define mx_int_prime 999999937
const int inf = 2000000000;
const double PI = acos(-1);
const double eps = 1e-9;
typedef long double ld;
#define MOD 1000000007
typedef long long ll;
const int mx=2e5+125;
ll pr[mx],ar[mx],br[mx];
#define PB push_back
#define endl '\n'
#define S second
#define F first
int main()
{
    faster();
    vector<int>v;
    int s;
    cin>>s;
    v.PB(s);
    int n=1000000;
    while(n--){
        if(s%2==0)
        {
            s/=2;
            v.PB(s);
        }
        else
        {
            s=3*s+1;
            v.PB(s);
        }
    }
    set<int>st;
    for(int i=0; i<v.size(); i++){
        if(st.count(v[i])){
            cout<<i+1<<endl;
            break;
        }
        else
            st.insert(v[i]);
    }


    return 0;
}

