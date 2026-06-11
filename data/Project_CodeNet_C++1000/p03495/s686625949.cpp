#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include <complex>
#include <iomanip>
#include <cmath>
#include <string>
#include <queue>
#include <stack>
#include <cstring>
#include <set>

#define ll long long
#define ld long double
#define HS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define INF 0x3f3f3f3f3f3f3f3f
#define point complex <double>
#define all(a) a.begin(), a.end()
#define pi acos(-1)
#define mod 1000000007


using namespace std;

int main() {

    HS;
    int n,k;
    cin>>n>>k;
    map < int , int > freq;
    set < int > st;
    vector < int > vec;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        freq[x]++;
        st.insert(x);
    }
    if(st.size()<=k)
        cout << 0 << endl;
    else{
        for(int i=1;i<=200000;i++)
        {
            if(freq[i])
                vec.push_back(freq[i]);
        }
        sort(all(vec));
        ll ans=0;
        int temp=st.size();
        for(int i=0;i<vec.size() && temp!=k;i++)
        {
            ans+=vec[i];
            temp--;
        }
        cout << ans << endl;
    }

   return 0;

}